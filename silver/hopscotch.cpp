// Author: envy <3 uwu
// Problem: Problem 2. Cow Hopscotch (Silver)
// Attempted: 2021-12-18 08:43:41 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
const int MOD = 1e9+7;

int grid[100][100], dp[100][100];
main(){
	ifstream cin("hopscotch.in");
	ofstream cout("hopscotch.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k; cin>>n>>m>>k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>grid[i][j];
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int r = i+1; r < n; r++){
				for(int c = j+1; c < m; c++){
					if(grid[i][j] != grid[r][c]){
						dp[r][c] += dp[i][j];
						dp[r][c] %= MOD;
					}
				}
			}
		}
	}
	cout<<dp[n-1][m-1];
}
