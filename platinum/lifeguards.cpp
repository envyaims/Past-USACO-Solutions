// add me on genshin impact! 607984574
// Problem: Problem 1. Lifeguards
// Attempted: 2024-06-22 14:05:41 EST

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#ifdef UwU
#include "C:\genshin_impact\keqing.cpp"
#else
#define debug(...) 0
#endif
using namespace std;

template<typename T>
struct compress{
	vector<T> v;
	int n;
	compress(vector<T> _v){
		v = _v;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		n = v.size();
	}
	int operator()(T x){
		auto it = lower_bound(v.begin(), v.end(), x);
		assert(it != v.end() && *it == x);
		return it - v.begin();
	}
	int inv(int x){
		return v[x];
	}
};

void ckmax(int& a, int b){
	a = max(a, b);
}

int main(){
	ifstream cin("lifeguards.in");
	ofstream cout("lifeguards.out");
	
	int n, k; cin >> n >> k;
	vector<pair<int, int>> a(n);
	for(auto& i: a){
		 cin >> i.first >> i.second;
	}
	
	sort(a.begin(), a.end());
	
	vector<int> relevant;
	for(int i = 0; i < n; i++){
		relevant.push_back(a[i].first);
		relevant.push_back(a[i].second);
	}

	compress<int> comp(relevant);
	vector<vector<int>> start(comp.n), end(comp.n);
	for(int i = 0; i < n; i++){
		start[comp(a[i].first)].push_back(i);
		end[comp(a[i].second)].push_back(i);
	}
	
	vector<vector<int>> dp(comp.n, vector<int>(k + 1, -1e9));
	
	set<int> overlap, non_overlap;
	for(int i = 0; i < comp.n; i++){
		for(int j: end[i]){
			if(overlap.count(j)){
				overlap.erase(j);
				non_overlap.insert(j);
			}
		}
		
		// case 4: don't choose
		if(i){
			for(int del = 0; del <= start[i].size(); del++){
				for(int j = del; j <= k; j++){
					ckmax(dp[i][j], dp[i - 1][j - del]);
				}
			}
		}
		
		if(start[i].empty()) continue;
		
		int use = start[i].back();
		int len = a[use].second - a[use].first;
		
		// case 1: keep this and leftmost that overlaps
		if(!overlap.empty()){
			int cur = *overlap.begin();
			int beg = comp(a[cur].first);
			int en = a[cur].second;
			int between = use - cur - 1;
			
			// debug(use, between, "case1");
			
			for(int j = between; j <= k; j++){
				ckmax(dp[i][j], dp[beg][j - between] + len - (en - a[use].first));				
			}
		}
		
		// case 2: keep no overlaps
		if(!non_overlap.empty()){
			int cur = *non_overlap.rbegin();
			int beg = comp(a[cur].first);
			assert(a[cur].second < a[use].first);
			int between = use - cur - 1;
			
			for(int j = between; j <= k; j++){
				ckmax(dp[i][j], dp[beg][j - between] + len);
			}
		}
		
		// case 3: only keep this interval
		for(int j: start[i]){
			if(j <= k) ckmax(dp[i][j], a[j].second - a[j].first);
		}
		
		overlap.insert(use);
	}
	
	int ans = 0;
	for(int i = 0; i < comp.n; i++){
		ans = max(ans, dp[i][k]);
	}
	cout << ans << endl;
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/