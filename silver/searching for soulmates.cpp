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

int test(int a, int b){
	if(a == b)return 0;
	if(a > b){
		// if a is even, then divide 2 rn
		// else add 1 to make it even and then divide by 2 lol
		int odd = a % 2;
		return 1 + odd + test((a + odd)/2,b);
	}
	else{
		int odd = b % 2;
		return min(b - a, 1 + odd + test(a, b/2));
	}
}

void solve() {
    int a,b; cin>>a>>b;
    cout<<test(a,b)<<"\n";
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
