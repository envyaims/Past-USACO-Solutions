// Author: envy
// Problem: Problem 2. Milk Factory from USACO - USACO 2019 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=940
// Limits: 4000 ms, 256 MB
// Attempted: 2021-10-10 17:49:23 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T> void max_self(T& a, T b){a = max(a,b);}
template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;
using secondpq = priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll; const ll INF = 1e18; const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};
#define int long long
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}

int n;
vector<int> times(101,0);
vector<int> graph[101];

void dfs(int node, vector<bool>& visited){
	if(visited[node])return;
	visited[node] = true;
	times[node]++;
	for(int i: graph[node]){
		dfs(i,visited);
	}
}

void doStuff(){
	freopen("factory.in","r",stdin);
	freopen("factory.out","w",stdout);
	cin>>n;
	for(int i = 0; i < n-1; i++){
		int a,b; cin>>a>>b;
		graph[a].pb(b);
	}
	
	for(int i = 1; i <= n; i++){
		vector<bool> visited(n+1,false);
		dfs(i,visited);
	}
	for(int i = 1; i <= n; i++){
		if(times[i] == n){
			print(i);
			return;
		}
	}
	debug(times);
	print(-1);
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){
		doStuff();
	}
}
