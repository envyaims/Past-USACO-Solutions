// Problem: Problem 3. Fence Planning
// Contest: USACO - USACO 2019 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=944
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file fenceplan.in  
// Output: file fenceplan.out  
// Attempted: 2021-08-04 09:02:43 EST
// all test cases passed lol

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

vector<int> graph[696969];
vector<pair<ll,ll>> cows;
vector<bool> visited(696969);
ll minx = INF, maxx = -INF, miny = INF, maxy = -INF;

void dfs(int node){
	if(visited[node])return;
	visited[node] = true;
	minx = min(minx, cows[node].F);
	maxx = max(maxx, cows[node].F);
	miny = min(miny, cows[node].S);
	maxy = max(maxy, cows[node].S);
	for(auto n: graph[node]){
		dfs(n);
	}
}

void doStuff(){
	freopen("fenceplan.in","r",stdin);
	freopen("fenceplan.out","w",stdout);
	int n,m; ri(n,m);
	for(int i = 0; i < n; i++){
		ll a,b; ri(a,b);
		cows.pb(mp(a,b));
	}
	
	for(int i = 0; i < m; i++){
		ll a,b; ri(a,b);
		graph[a-1].pb(b-1);
		graph[b-1].pb(a-1);
	}
	
	ll ans = INF;
	for(int i = 0; i < n; i++){
		if(visited[i]) continue;
		dfs(i);
		ans = min(ans, 2*((maxx-minx) + (maxy-miny)));
		minx = INF, maxx = -INF, miny = INF, maxy = -INF;
	}
	
	print(ans);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
