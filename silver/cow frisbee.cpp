#include <bits/stdc++.h>

using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(), x.end()
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int& i: a)
        cin>>i;
    vector<int> at(n+1);
    for(int i = 0; i < n; i++){
        at[a[i]] = i;
    }
    set<int> order;
    int ans = 0;
    for(int i = n; i >= 1; i--){
        int idx = at[i];
        auto it = order.upper_bound(idx);
        if(it != order.end()){
            ans += *it-idx+1;
        }
        if(it != order.begin()){
            --it;
            ans += idx-*it+1;
        }
        order.insert(idx);
    }
    cout<<ans;



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
