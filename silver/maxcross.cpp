// Problem: Problem 2. Why Did the Cow Cross the Road II
// Contest: USACO - USACO 2017 February Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=715
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file maxcross.in  
// Output: file maxcross.out  
// Attempted: 2021-08-01 12:05:07 EST

#include <bits/stdc++.h>
using namespace std;

inline namespace fastio {
	const int BSZ = 1<<15; 
	char ibuf[BSZ]; int ipos, ilen;
	char nc() {
		if (ipos == ilen) {
			ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);
			if (!ilen) return EOF;
		}
		return ibuf[ipos++];
	}
	template<class T> void ri(T& x) { // read int or ll
		char ch; int sgn = 1;
		while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
		x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
		x *= sgn;
	}
	template<class T> void rc(T& x){ // read char
		x = nc();
		while(isspace(x)){
			x = nc();
		}
	}
	template<class T, class... Ts> void ri(T& t, Ts&... ts) { 
		ri(t); ri(ts...); } // read ints
}

typedef long long ll;
const int INF = 1e18, MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())


void doStuff(){
	freopen("maxcross.in","r",stdin);
	freopen("maxcross.out","w",stdout);
	int n, k, b; ri(n,k,b);
	vector<int> signals(n+1,0);
	for(int i = 0; i < b; i++){
		int a; ri(a);
		signals[a] = 1;
	}
	
	vector<int> prefix(n+1,0);
	for(int i = 1; i <= n; i++){
		prefix[i] = prefix[i-1] + signals[i];
	}
	
	int ans = k;
	
	for(int i = k; i <= n; i++){
		ans = min(ans,prefix[i] - prefix[i-k]);
	}
	
	print(ans);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
