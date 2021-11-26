// Author: envy
// Problem: Problem 3. Spaced Out from USACO - USACO 2021 January Contest, Silver
// URL: http://usaco.org/index.php?page=viewproblem2&cpid=1088
// Limits: 4000 ms, 256 MB
// Attempted: 2021-11-11 08:21:54 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<vector<int>> grid(n,vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>grid[i][j];
		}
	}
	
	int horans = 0, verans = 0;
	for(int i = 0; i < n; i++){
		int osum = 0, esum = 0;
		for(int j = 0; j < n; j++){
			(j&1 ? osum : esum) += grid[i][j];
		}
		horans += max(osum,esum);
	}
	
	for(int i = 0; i < n; i++){
		int osum = 0, esum = 0;
		for(int j = 0; j < n; j++){
			(j&1 ? osum : esum) += grid[j][i];
		}
		verans += max(osum,esum);
	}
	debug(horans,verans);
	cout<<max(horans,verans);
	
}