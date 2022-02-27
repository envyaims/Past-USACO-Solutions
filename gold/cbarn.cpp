// author: envy uwu <3
// problem: Problem 1. Circular Barn
// created: 2/26/2022 10:01 PM

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
    ifstream cin("cbarn.in");
    ofstream cout("cbarn.out");
    int n; cin>>n;
    vector<int> a(n);
    for(int& i: a)cin>>i;

    int mn = 1e9, startfrom;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i]-1;
        if(sum < mn){
            startfrom = i;
            mn = sum;
        }
    }
    if(++startfrom == n){
        startfrom = 0;
    }
    rotate(a.begin(),a.begin()+startfrom,a.end());
    deque<int> dq;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i]; j++){
            dq.push_back(i);
        }
        a[i] = 0;
        if(!dq.empty()){
            int f = dq.front();
            dq.pop_front();
            ans += (f-i)*(f-i);
        }
    }
    cout<<ans<<endl;

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
