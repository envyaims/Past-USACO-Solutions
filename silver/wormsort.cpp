// Author: envy
// Problem: Problem 3. Wormhole Sort from USACO - USACO 2020 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=992
// Limits: 4000 ms, 256 MB
// Attempted: 2021-09-10 19:39:28 EST

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
int n, m;
vector<int> nums;
vector<int> pos;
vector<array<int,3>> swaps;

vector<bool> visited;
int compno = 0;
vector<int> compnum;

void dfs(int node, vector<vector<int>>& graph){
	if(visited[node])return;
	visited[node] = true;
	compnum[node] = compno;
	for(int i: graph[node]){
		dfs(i,graph);
	}
}

bool check(int x){
	vector<vector<int>> graph(n);
	for(auto a: swaps){
		if(a[2] >= x){
			graph[a[0]].pb(a[1]);
			graph[a[1]].pb(a[0]);
		}
	}
	
	fill(all(visited),false);
	fill(all(compnum),-1);
	compno = 0;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs(i,graph);
			compno++;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(pos[i+1] != i){
			if(compnum[pos[i+1]] != compnum[i]){
				return false;
			}
		}
	}
	return true;
	
	
}
void doStuff(){
	ri(n,m);
	nums.resize(n);
	pos.resize(n+1);
	visited.resize(n);
	compnum.resize(n);
	
	for(int i = 0; i < n; i++){
		int a; ri(a);
		nums[i] = a;
		pos[a] = i;
	}
	if(is_sorted(all(nums))){
		print(-1);
		return;
	}
	
	swaps.resize(m);
	for(int i = 0; i < m; i++){
		int a,b,w; ri(a,b,w);
		swaps[i] = {a-1,b-1,w};
	}
	
	int start = 1, end = 1e9;
	while(start < end-1){
		int mid = start + (end-start)/2;
		if(check(mid)){
			start = mid;
		}
		else end = mid;
	}
	debug(check(9));
	debug(check(10));
	print(start);
	
}

signed main(){
	freopen("wormsort.in","r",stdin);
	freopen("wormsort.out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);int t = 1;
	// ri(t);
	while(t--)doStuff();
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}