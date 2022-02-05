#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else

#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"

#endif

using namespace std;
#define int long long

int cnt(vector<int> a, vector<int> b){
    int win = 0, tot = 16;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(a[i] > b[j])win++;
            else if(a[i] == b[j])tot--;

        }
    }
    return win+win-tot;
}

bool beat(vector<int> a, vector<int> b){
    return cnt(a,b) > 0;
}
bool tie(vector<int> a, vector<int> b){
    return cnt(a,b) == 0;
}

const int n = 4;
void solve() {
    vector<int> a(n), b(n);
    for(int& i: a)cin>>i;
    for(int& i: b)cin>>i;
    if(tie(a,b)){
        puts("no");
        return;
    }
    if(beat(b,a)){
        swap(a,b);
    }
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            for(int k = 1; k <= 10; k++){
                for(int p = 1; p <= 10; p++){
                    vector<int> c = {i,j,k,p};
                    if(beat(b,c) && beat(c,a)){
                        puts("yes");
                        return;
                    }
                }
            }
        }
    }
    puts("no");


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}



