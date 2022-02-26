// author: envy uwu <3
// problem: Problem 3. Teamwork
// created: 2/26/2022 10:03 AM

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
    ifstream cin("teamwork.in");
    ofstream cout("teamwork.out");
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int& i: a)cin>>i;
    vector<int> dp(n); // maximum skill levels for cow up to i
    for(int i = 0; i < n; i++){
        int maxskill = 0;
        for(int j = i; j >= i-k+1 && j >= 0; j--){
            maxskill = max(maxskill,a[j]);
            if(j){
                dp[i] = max(dp[i], dp[j-1] + (i-j+1) * maxskill);
            }
            else dp[i] = max(dp[i], maxskill * (i-j+1));
        }
    }
    cout<<dp[n-1]<<endl;
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
