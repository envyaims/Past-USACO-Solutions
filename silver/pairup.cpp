// Problem: Problem 1. Paired Up
// Contest: USACO - USACO 2017 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=738
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file pairup.in  
// Output: file pairup.out  
// Attempted: 2021-08-01 16:28:56 EST

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
	freopen("pairup.in","r",stdin);
	freopen("pairup.out","w",stdout);
	int n; ri(n);
	vector<pair<int,int>> nums(n);
	for(int i = 0; i < n; i++){
		int a,b; ri(a,b);
		nums[i] = mp(b,a);
	}
	sort(all(nums));
	int ans = 0;
	int a = 0;
	int b = n-1;
	while(a <= b){
		int occur = min(nums[a].S,nums[b].S);
		if(a == b)occur/=2;
		ans = max(ans,nums[a].F + nums[b].F);
		nums[a].S -= occur;
		nums[b].S -= occur;
		if(nums[a].S == 0)a++;
		if(nums[b].S == 0)b--;
	}
	print(ans);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
