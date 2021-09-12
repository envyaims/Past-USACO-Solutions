// Author: envy
// Problem: Problem 3. Milk Visits from USACO - USACO 2019 December Contest, Silver
// URL: http://www.usaco.org/ind.php?page=viewproblem2&cpid=968
// Limits: 4000 ms, 256 MB
// Attempted: 2021-09-11 20:31:16 EST

#ifndef LOCAL
#define debug(...) 0
#include <bits/stdc++.h>
#else
#include "C:\programmingfunnyxd\debug.cpp"
#include "C:\programmingfunnyxd\includeordie.h"
#endif
using namespace std;
inline namespace readio { const int BSZ = 1<<15; char ibuf[BSZ]; int ipos, ilen;char nc() {if (ipos == ilen) {ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);if (!ilen) return EOF;}return ibuf[ipos++];}
template<class T> void ri(T& x) {char ch; int sgn = 1;while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');x *= sgn;}
template<class T> void rc(T& x){ x = nc();while(isspace(x))x = nc();}template<class T, class... Ts> void ri(T& t, Ts&... ts) {ri(t);ri(ts...);}
template<class str>void rs(str& x) { char ch; while (isspace(ch = nc()));do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);}}
template<typename T> void max_self(T& a, T b){a = max(a,b);}template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
// template<typename T> pow(T a,T b,T m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b/=2;a=(a*a)%m;}return ans;}
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;template<typename T> using maxpq = priority_queue<T>;
typedef priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond> secondpq;
typedef long long ll; const ll INF = 1e18; const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define bpop(x) __builtin_popcount(x)
#define fillarr(arr,n,am) fill(arr[0],arr[n],am)
#define readarr(arr) for(int &i: arr)ri(i);
#define readchararr(arr)for(int &i: arr)rc(i);
#define readgrid(arr, n, m)for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)ri(arr[i][j]);
#define readchargrid(arr, n, m)for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)rc(arr[i][j]);
const int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
#define int long long // fight me

int n,m;
char type[100001];
vector<int> graph[100001];
vector<bool> visited(100001);

int ind = 1;
vector<int> gonly(100001,-1);
vector<int> honly(100001,-1);

int startpt, endpt;
char target;

void dfs(int i, char init){
	if(visited[i] || type[i] != init)return;
	visited[i] = true;
	if(init == 'G'){
		gonly[i] = ind;
	}
	else honly[i] = ind;
	for(int j: graph[i]){
		dfs(j,init);
	}
}

void doStuff(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>type[i];
	}
	for(int i = 0 ; i < n-1; i++){
		int a,b; cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i,type[i]);
			ind++;
		}
	}
	while(m--){
		cin>>startpt>>endpt>>target;
		if(target == 'H'){
			if(gonly[startpt] == -1 || gonly[endpt] == -1){
				cout<<1;
			}
			else if(gonly[startpt] == gonly[endpt])cout<<0;
			else cout<<1;
			debug(gonly[startpt]);
		}
		else{
			if(honly[startpt] == -1 || honly[startpt] == -1){
				cout<<1;
			}
			else if(honly[startpt] == honly[endpt])cout<<0;
			else cout<<1;
		}
	}
	
	
	
}

signed main(){
	freopen("milkvisits.in","r",stdin);
	freopen("milkvisits.out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);int t = 1;
	// ri(t);
	while(t--)doStuff();
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}