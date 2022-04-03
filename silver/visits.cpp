// Author: envy <3 uwu
// Problem: Problem 1. Visits
// Attempted: 2022-04-03 08:26:06 EST
// check out this video its pretty cool https://www.youtube.com/watch?v=mKvXIgaLEJc


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
const int N = 1e5+5;
vector<int> graph[N], revgraph[N];
int val[N], compval[N], comp[N];
bool vis[N];
vector<int> path;
int compno = 1;

void dfs(int node){
    vis[node] = true;
    for(int i: graph[node]){
        if(!vis[i]){
            dfs(i);
        }
    }
    path.push_back(node);
}

void dfs2(int node){
    comp[node] = compno;
    for(int i: revgraph[node]){
        if(!comp[i]){
            dfs2(i);
        }
    }
}

void solve() {
    int n; cin>>n;
    for(int i = 1; i <= n; i++){
        int a,v; cin>>a>>v;
        graph[i].push_back(a);
        revgraph[a].push_back(i);
        val[i] = v;
    }
    
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    reverse(all(path));
    
    for(int i: path){
        if(!comp[i]){
            dfs2(i);
            compno++;
        }
    }
    
    vector<int> compmin(compno,1e9);
    for(int i = 1; i <= n; i++){
        compmin[comp[i]] = min(compmin[comp[i]],val[i]);
        compval[comp[i]] += val[i];
    }
    
    int ans = 0;
    for(int i = 1; i < compno; i++){
        //printf("%d: %d %d\n",i,compmin[i],compval[i]);
        if(compmin[i] == compval[i]){
            ans += compval[i];
        }
        else ans += compval[i] - compmin[i];
    }
    cout<<ans<<endl;
    
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
