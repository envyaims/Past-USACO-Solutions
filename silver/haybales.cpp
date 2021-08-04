// Problem: Problem 1. Counting Haybales
// Contest: USACO - USACO 2016 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=666
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file haybales.in  
// Output: file haybales.out  
// Attempted: 2021-08-02 13:42:08 EST

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
	template<class str>void rs(str& x) { // read str
		char ch; while (isspace(ch = nc()));
		do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);
	}
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
	freopen("haybales.in","r",stdin);
	freopen("haybales.out","w",stdout);
	int n,q; ri(n,q);
	vector<ll> nums(n);
	for(int i = 0; i < n; i++)ri(nums[i]);
	sort(all(nums));
	while(q--){
		ll a,b; ri(a,b);
		auto it = lower_bound(all(nums),a);
		auto it2 = prev(upper_bound(all(nums),b),1);
		
		print(distance(nums.begin(), it2) - distance(nums.begin(), it) +1);
	}
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
