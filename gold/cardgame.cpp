// Problem: Problem 1. High Card Low Card (Gold)
// Contest: USACO - USACO 2015 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=573
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file cardgame.in  
// Output: file cardgame.out  
// Attempted: 2021-08-02 11:37:29 EST

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
	freopen("cardgame.in","r",stdin);
	freopen("cardgame.out","w",stdout);
	int n; ri(n);
	set<int> bessie;
	vector<int> elsie1, elsie2;
	for(int i = 1; i <= 2*n; i++)bessie.insert(i);
	for(int i = 0; i < n/2; i++){
		int a; ri(a);
		elsie1.pb(a);
		bessie.erase(a);
	}
	for(int i = 0; i < n/2; i++){
		int a; ri(a);
		elsie2.pb(a);
		bessie.erase(a);
	}
	
	sort(all(elsie1));
	sort(all(elsie2));
	
	int ans = 0;
	for(int i = (n/2)-1; i >= 0; i--){
		auto it = bessie.upper_bound(elsie1[i]);
		if(it != bessie.end()){
			bessie.erase(prev(bessie.end(),1));
			ans++;
		}
	}
	
	bessie.insert(-1);
	for(int i = 0; i < n/2; i++){
		auto it = prev(bessie.upper_bound(elsie2[i]),1);
		if(*it != -1){
			bessie.erase(it);
			ans++;
		}
		
	}
	print(ans);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
