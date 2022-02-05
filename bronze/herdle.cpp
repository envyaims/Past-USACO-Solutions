#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else

#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"

#endif

using namespace std;
#define int long long
const int n = 3;

void solve() {
    char guess[n][n], answer[n][n];
    map<char,int> acnt, gcnt;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin>>guess[i][j];
            gcnt[guess[i][j]]++;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin>>answer[i][j];
            acnt[answer[i][j]]++;
        }

    int y = 0, g = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(answer[i][j] == guess[i][j]){
                g++;
                gcnt[answer[i][j]]--;
                acnt[answer[i][j]]--;
            }
        }
    }
    for(char i = 'A'; i <= 'Z'; i++){
        y += min(gcnt[i],acnt[i]);
    }
    cout<<g<<"\n"<<y;


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}



