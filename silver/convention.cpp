// Problem: Problem 1. Convention
// Contest: USACO - USACO 2018 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=858
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file convention.in  
// Output: file convention.out  
// Attempted: 2021-08-03 19:34:42 EST

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
const ll INF = 1e18;
const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())

int n,m,c;
vector<ll> nums;

bool check(ll x){
	// maxinum waiting time is x;
	int groups = 1;
	ll init = nums[0];
	int initcows = 0;
	for(int i = 1; i < n; i++){
		if(nums[i] - init > x || i+1 - initcows > c){
			groups++;
			init = nums[i];
			initcows = i;
		}
	}
	return (groups <= m);
}

ll firstTrue(ll start, ll end, function<bool(ll)> f){
	for(end++; start < end; ){
		ll mid = start + (end-start)/2;
		if(f(mid)) end = mid;
		else start = mid+1;
	}
	return start;
}

void doStuff(){
	freopen("convention.in","r",stdin);
	freopen("convention.out","w",stdout);
	ri(n,m,c);
	for(int i = 0; i < n; i++){
		ll a; ri(a);
		nums.pb(a);
	}
	sort(all(nums));
	
	cout<< firstTrue(0,INF,check);
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
