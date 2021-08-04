// Problem: Problem 3. Moocast
// Contest: USACO - USACO 2016 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=668
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file moocast.in  
// Output: file moocast.out  
// Attempted: 2021-08-04 14:55:51 EST
// AC

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

vector<int> graph[300];
int n;


int dfs(int node, vector<bool>& visited){
	visited[node] = true;
		int count = 0;
	for(auto i: graph[node]){
		if(!visited[i]){
			visited[i] = true;
			count += dfs(i,visited) + 1;
		}
	}
	return count;
}

void doStuff(){
	freopen("moocast.in","r",stdin);
	freopen("moocast.out","w",stdout);
	ri(n);
	vector<int> x(n+1);
	vector<int> y(n+1);
	vector<int> p(n+1);
	for(int i = 1; i <= n; i++){
		ri(x[i],y[i],p[i]);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= p[i] * p[i]){
				graph[i].pb(j);
			}
		}
	}
	
	int ans = 1;
	for(int i = 1; i <= n; i++){
		vector<bool> visited(300);
		int cnt = dfs(i,visited) + 1;
		ans = max(ans, cnt);
	}
	print(ans);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
