#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    int ans = 0;
    for(int i = 1; i <= n-1; i++){
        if(a[i+1] > a[i]){
            if(i + 2 > n){
                cout<<-1<<"\n";
                return;
            }
            int diff = a[i+1] - a[i];
            a[i+2] -= diff;
            a[i+1] -= diff;
            if(a[i+2] < 0 || a[i+1] < 0){
               // cout<<i<<"\n";
                cout<<-1<<"\n";
                return;
            }
            ans += diff*2;
        }
        else if(a[i] > a[i+1]){
            int diff = a[i] - a[i+1];
            ans += diff*i;
            if(i % 2 == 1){
                cout<<-1<<"\n";
                return;
            }
        }
    }
    cout<<ans<<"\n";

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }

}
