// author: envy <3

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;
using ll = long long;
const int N = 105;
vector<int> down[N], up[N];


vector<pair<int,int>> dfsup(int node){
	vector<pair<int,int>> tmp;
	auto dfs = [&](auto self, int node, int cnt) -> void{
		for(int i: up[node]){
			tmp.emplace_back(cnt + 1, i);
			self(self, i, cnt + 1);
		}
	};
	dfs(dfs, node, 0);
	sort(tmp.begin(), tmp.end());
	return tmp;
}

vector<pair<int,int>> dfsdown(int node){
	vector<pair<int,int>> tmp;
	auto dfs = [&](auto self, int node, int cnt) -> void{
		for(int i: down[node]){
			tmp.emplace_back(cnt + 1, i);
			self(self, i, cnt + 1);
		}
	};
	dfs(dfs, node, 0);
	sort(tmp.begin(), tmp.end());
	return tmp;
}

int find(vector<pair<int,int>> x, int y){
	for(auto i: x){
		if(i.second == y){
			return i.first;
		}
	}
	return -1;
}

void solve(){
	ifstream cin("family.in");
	ofstream cout("family.out");
	
	int n; cin >> n;
	string A,B; cin >> A >> B;
	int cnt = 1;
	map<string, int> mapping;
	mapping[A] = cnt++;
	mapping[B] = cnt++;
	int a = mapping[A], b = mapping[B];
	for(int i = 0; i < n; i++){
		string u,v ; cin >> u >> v;
		if(mapping[u] == 0){
			mapping[u] = cnt++;
		}
		if(mapping[v] == 0){
			mapping[v] = cnt++;
		}
		up[mapping[v]].push_back(mapping[u]);
		down[mapping[u]].push_back(mapping[v]);
	}
	
	auto printa = [&](string s){
		cout << A << " is the " << s << " of " << B << endl;
	};
	
	auto printb = [&](string s){
		cout << B << " is the " << s << " of " << A << endl;
	};
	
	vector<pair<int,int>> upa = dfsup(a), upb = dfsup(b);
	if(upa.size() > 0 && upb.size() > 0){
		if(upa[0] == upb[0]){
			cout << "SIBLINGS";
			return;
		}
	}
	
	// handle case 2
	vector<pair<int,int>> downa = dfsdown(a), downb = dfsdown(b);
	int f1 = find(downb, a);
	if(f1 != -1){
		if(f1 == 1){
			printb("mother");
		}
		else if(f1 == 2){
			printb("grand-mother");
		}
		else{
			string s;
			for(int i = 0; i < f1 - 2; i++){
				s += "great-"; 
			}
			printb(s + "grand-mother");
		}
		return;
	}
	f1 = find(downa, b);
	if(f1 != -1){
		if(f1 == 1){
			printa("mother");
		}
		else if(f1 == 2){
			printa("grand-mother");
		}
		else{
			string s;
			for(int i = 0; i < f1 - 2; i++){
				s += "great-"; 
			}
			printa(s + "grand-mother");
		}
		return;
	}
	
	
	// handle aunts
	for(auto i: upa){
		vector<pair<int,int>> cur;
		//dfsdown(i.second);
		for(int j: down[i.second]){
			cur.push_back({0, j});
		}
		int v = find(cur, b);
		if(v != -1 && i.first > 1){
			string s;
			for(int j = 0; j < i.first - 2; j++){
				s += "great-";
			}
			printb(s + "aunt");
			return;
		}
	}
	
	for(auto i: upb){
		vector<pair<int,int>> cur;
		for(int j: down[i.second]){
			cur.push_back({0, j});
		}
		int v = find(cur, a);
		if(v != -1 && i.first > 1){
			string s;
			for(int j = 0; j < i.first - 2; j++){
				s += "great-";
			}
			printa(s + "aunt");
			return;
		}
	}
	
	// handle cousins
	for(auto i: upa){
		if(find(upb, i.second) != -1){
			cout << "COUSINS";
			return;
		}
	}
	
	cout << "NOT RELATED";
	
	
	
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1; 
	// cin >> t;
	while(t--){
		solve();
	}
}
