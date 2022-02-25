// Author: envy <3 uwu
// Problem: Problem 2. Modern Art 3
// Attempted: 2022-02-25 09:57:26 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
const int N = 305;
int dp[N][N];

void solve() {
	
    int n; cin>>n;
    vector<int> a(n);
    for(int& i: a)cin>>i;
    for(int i = 0; i < N; i++){
    	fill(dp[i],dp[i]+N,1e9);
    }
    for(int i = 0; i < n; i++)dp[i][i] = 1;
    
    for(int len = 0; len <= n; len++){
    	for(int i = 0; i < n-len; i++){
    		for(int j = i; j < i+len; j++){
    			if(a[i] == a[i+len]){
    				dp[i][i+len] = min(dp[i][i+len],dp[i][j]+dp[j+1][i+len]-1);
    			}
    			else dp[i][i+len] = min(dp[i][i+len],dp[i][j]+dp[j+1][i+len]);
    		}
    	}
    }
    cout<<dp[0][n-1];
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
