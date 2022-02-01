#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;
#define int long long

int n, m;
const int MAXN = 5e5+5;
vector<int> graph[MAXN];
vector<set<int>> comps;
bool visited[MAXN];
int cnt = 0;
int onecomp, ncomp;

void dfs(int node){
	if(node == 1)onecomp = cnt-1;
	if(node == n)ncomp = cnt-1;
    visited[node] = true;
    comps.back().insert(node);
    for(int i: graph[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

void solve() {
    cin>>n>>m;
    fill(visited,visited+n+1,false);
    cnt = 0;
    for(int i = 1; i <= n; i++){
        graph[i].clear();
    }
    comps.clear();
    for(int i = 0; i < m; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            comps.push_back({});
            dfs(i);
        }
    }
    
    auto get = [&](int a, int b) -> int{
		int ret = 1e9;
		for(int i: comps[a]){
			auto it = comps[b].lower_bound(i);
			if(it != comps[b].end()){
				ret = min(ret,*it-i);
			}
			if(it != comps[b].begin()){
				--it;
				ret = min(ret,i-*it);
			}
		}
		return ret * ret;
	};
	
	auto mincost = [&](int a, int b) -> int{
		if(comps[a].size() > comps[b].size()){
			return get(b,a);
		}
		return get(a,b);
	};
	
	int ans = mincost(onecomp,ncomp);
	for(int i = 0; i < cnt; i++){
		if(i == onecomp || i == ncomp)continue;
		int x = mincost(onecomp,i);
		int y = mincost(ncomp,i);
		ans = min(ans,x+y);
	}
	cout<<ans<<"\n";


}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
 
}

