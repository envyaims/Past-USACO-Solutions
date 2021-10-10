// Author: envy
// Problem: Problem 2. The Great Revegetation from USACO - USACO 2019 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=916
// Limits: 4000 ms, 256 MB
// Attempted: 2021-10-10 17:34:14 EST

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

vector<int> graph[101];
vector<int> type(101);
bool visited[101];
int n,m;

void dfs(int node){
	if(visited[node])return;
	visited[node] = true;
	
	vector<bool> grass(5,true);
	for(int i: graph[node]){
		grass[type[i]] = false;
	}
	for(int i = 1; i <= 4; i++){
		if(grass[i]){
			type[node] = i;
			break;
		}
	}
	// for(int i: graph[node]){
		// dfs(i);
	// }
	
}
void doStuff(){
	ifstream cin("revegetate.in");
	ofstream cout("revegetate.out");
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a,b; cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	
	for(int i = 1; i <= n; i++){
		sort(all(graph[i]));
	}
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout<<type[i];
	}
	
	
	
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