// author: envy uwu <3
// problem: Problem 3. Disruption
// created: 1/27/2022 9:57 PM

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

template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int MAXN = 50005;
set<pair<int,int>> minedge[MAXN];
vector<int> graph[MAXN];
vector<pair<int,int>> origedges;
int par[MAXN], res[MAXN];

void dfs(int node, int p){
    par[node] = p;
    for(int i: graph[node]){
        if(i != p){
            dfs(i,node);
            if(minedge[i].size() > minedge[node].size()){
                swap(minedge[i],minedge[node]);
            }
            for(auto j: minedge[i]){
                if(minedge[node].count(j)){
                    minedge[node].erase(j);
                }
                else minedge[node].insert(j);
            }
        }
    }
    if(minedge[node].empty()){
        res[node] = -1;
    }
    else res[node] = minedge[node].begin() -> F;
}

void solve() {
    int n,m; cin>>n>>m;
    for(int i = 0; i < n-1; i++){
        int u,v; cin>>u>>v;
        origedges.emplace_back(u,v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0; i < m; i++){
        int u,v,c; cin>>u>>v>>c;
        minedge[u].insert({c,i});
        minedge[v].insert({c,i});
    }
    dfs(1,1);
    for(auto i: origedges){
        if(par[i.S] == i.F){
            cout<<res[i.S]<<"\n";
        }
        else cout<<res[i.F]<<"\n";
    }

}

signed main() {
    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }

}
