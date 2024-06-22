// Author: envy <3 uwu
// Problem: Problem 2. Making Friends
// Attempted: 2023-03-11 08:04:10 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

const int N = 2e5 + 5;
set<int> g[N];
	
void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		g[min(u, v)].insert(max(u, v));
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		// cow i leaves el farm
		ans += sz(g[i]);
		if(!g[i].empty()){
			int f = *g[i].begin();
			g[i].erase(f);
			// small to large merge
			if(sz(g[i]) > sz(g[f])) g[i].swap(g[f]);
			for(int j: g[i]) g[f].insert(j);
		}
	}
	cout << ans - m << "\n";
	
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int T = 1;
	// cin >> T;
	for(int _ = 0; _ < T; _++){
		solve();
	}
}