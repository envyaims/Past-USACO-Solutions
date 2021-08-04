// Problem: Problem 3. Closing the Farm
// Contest: USACO - USACO 2016 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=644
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file closing.in  
// Output: file closing.out  
// Attempted: 2021-08-03 21:19:41 EST
// NO WAY HOW DID I GET AC LOL

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


vector<int> graph[3002];

void dfs(int node, vector<bool>& visited){
	if(visited[node])return;
	visited[node] = true;
	for(auto n: graph[node]){
		dfs(n,visited);
	}
}

void doStuff(){
	freopen("closing.in","r",stdin);
	freopen("closing.out","w",stdout);
	int n,m;
	ri(n,m);
	
	for(int i = 0; i < m; i++){
		int a,b; ri(a,b);
		graph[a].pb(b);
		graph[b].pb(a);
	}
	
	set<int> barns;
	
	for(int i = 1; i <= n; i++){
		barns.insert(i);
	}
	
	for(int i = 0; i < n; i++){
		if(i != 0){
			int a; ri(a);
			graph[a].clear();
			barns.erase(a);
		}
		
		vector<bool> visited(3002,false);
		
		bool can = true;
		for(int j: barns){
			dfs(j,visited);
			break;
		}
		
		for(int j: barns){
			if(!visited[j]){
				can = false;
				break;
			}
		}
		
		if(can)print("YES");
		else print("NO");
		
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
