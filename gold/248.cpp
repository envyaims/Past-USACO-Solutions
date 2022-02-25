// Author: envy <3 uwu
// Problem: Problem 3. 248
// Attempted: 2022-02-25 08:36:23 EST

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
const int N = 250;
int dp[N][N];

void solve() {
	freopen("248.in","r",stdin);
	freopen("248.out","w",stdout);
	int n; cin>>n;
	vector<int> a(n);
	for(int& i: a) cin>>i;
	for(int i = 0; i < n; i++){
		dp[i][i] = a[i];
	}
	int ans = 0;
	for(int len = 1; len <= n; len++){
		for(int i = 0; i < n-len; i++){
			for(int j = i; j <= i + len; j++){
				if(dp[i][j] == dp[j+1][i + len] && dp[i][j] != 0){
					dp[i][i+len] = max(dp[i][i+len], dp[i][j]+1);
				}
			}
			ans = max(ans,dp[i][i+len]);
		}
	}
	cout<<ans<<endl;
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
