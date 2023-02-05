#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	ll l, r, n; cin >> l >> r >> n;
	
	vector<pair<char, string>> replace(n+1);
	replace[0] = {'a', "a"};
	for(int i = 1; i <= n; i++){
		char c; string s; cin >> c >> s;
		replace[i] = {c, s};
	}
	
	vector<vector<int>> g(n+1);
	vector<vector<pair<int,int>>> need(26);
	// need[i] stores all that need char c
	g[0].resize(1,-1);
	need[0].push_back({0, 0});
	
	for(int i = 1; i <= n; i++){
		// connect all nodes that this replaces with
		for(auto j: need[replace[i].first - 'a']){
			// connect them
			g[j.first][j.second] = i;
		}
		need[replace[i].first - 'a'].clear();
		int sz = replace[i].second.size();
		g[i].resize(sz, -1);
		for(int j = 0; j < sz; j++){
			need[replace[i].second[j] - 'a'].push_back({i, j});
		}
	}
	vector<char> ans(r-l+1);
	vector<ll> subtree(n+1, -1);
	ll left = l;
	// precompute subtree sizes 
	ll cur = 0;
	auto dfs = [&](auto self, int node) -> ll{
		int sz = g[node].size();
		ll counter = 0;
		for(int i = 0; i < sz; i++){
			if(g[node][i] == -1){
				counter++;
				if(cur+counter >= l && cur+counter <= r){
					ans[cur+counter-l] = replace[node].second[i];
					left++;
					if(left > r){
						for(char i: ans){
							cout << i;
							assert(i != ' ');
						}
						exit(0);
					}
				}
			}
			else{
				ll tmp = counter;
				if(subtree[g[node][i]] == -1){
					cur += tmp;
					counter += self(self, g[node][i]);
					cur -= tmp;
				}
				else{
					ll L = cur + tmp, R = cur + tmp + subtree[g[node][i]];
					if(left <= r && left > L && left <= R){
						cur += tmp;
						self(self, g[node][i]);
						cur -= tmp;
					}
					counter += subtree[g[node][i]];
				}
				if(cur + counter > r) return subtree[node] = counter;
			}
		}
		return subtree[node] = counter;
	};
	dfs(dfs, 0);
	for(char i: ans){
		cout << i;
		assert(i != ' ');
	}
	cout << endl;
}
