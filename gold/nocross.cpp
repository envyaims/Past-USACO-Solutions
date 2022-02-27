// author: envy uwu <3
// problem: Problem 2. Why Did the Cow Cross the Road II
// created: 2/27/2022 8:31 AM

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

void solve() {
    ifstream cin("nocross.in");
    ofstream cout("nocross.out");
    int n; cin>>n;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i <= n; i++)
        cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    // dp[left index][right index]
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(abs(a[i] - b[j]) <= 4){
                // build a road
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max({dp[i-1][j-1],dp[i][j-1],dp[i-1][j], dp[i][j]});
        }
    cout<<dp[n][n]<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }

}
