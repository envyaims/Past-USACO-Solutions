// author: envy uwu <3
// problem: Problem 1. Redistributing Gifts
// created: 3/23/2022 8:35 PM

#include <bits/stdc++.h>

#ifndef LOCAL
#define debug(...) 0
#else

#include "C:\programmingfunnyxd\debug.cpp"

#endif

using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
const int N = 505;
vector<int> graph[N], revgraph[N];
bool vis[N], vis2[N];
vector<int> path;
set<int> comp;

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
    vis2[node] = true;
    for(int i: revgraph[node]){
        if(!vis2[i]){
            dfs2(i);
        }
    }
    comp.insert(node);
}

void solve() {
    int n; cin>>n;
    for(int i = 1; i <= n; i++){
        graph[i].resize(n);
        for(int j = 0; j < n; j++){
            cin>>graph[i][j];
        }
        while(graph[i].back() != i){
            graph[i].pop_back();
        }
        for(int j: graph[i]){
            revgraph[j].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(all(path));
    vector<int> ans(n+1);
    for(int i: path){
        if(!vis2[i]){
            dfs2(i);
            for(int j: comp){
                for(int k: graph[j]){
                    if(comp.count(k)){
                        ans[j] = k;
                        break;
                    }
                }
            }

            comp.clear();
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<endl;
    }



}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }

}
