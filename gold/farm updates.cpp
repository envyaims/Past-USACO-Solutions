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
const int MAXN = 2e5+5;
int n, q;
int ans[MAXN], deactive[MAXN],  remedge[MAXN];
bool noedge[MAXN], bad[MAXN];
vector<int> graph[MAXN];

void setans(int x, int t){
	if(ans[x] != 0)return;
	ans[x] = t;
	for(int i: graph[x]){
		setans(i,t);
	}
}

void solve() {
    cin>>n>>q;
    vector<pair<int,int>> edges;
    fill(remedge,remedge+MAXN,-1);
    fill(deactive,deactive+MAXN,-1);
    for(int i = 0; i < q; i++){
		char t; cin>>t;
		if(t == 'A'){
			int u,v; cin>>u>>v;
			edges.emplace_back(u,v);
		}
		else if(t == 'D'){
			int v; cin>>v;
			deactive[i] = v;
			bad[v] = true;
		}
		else{
			int v; cin>>v;
			remedge[i] = v-1;
			noedge[v-1] = true;
		}
	}
	for(int i = 0; i < (int)edges.size(); i++){
		if(!noedge[i]){
			graph[edges[i].F].push_back(edges[i].S);
			graph[edges[i].S].push_back(edges[i].F);
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(!bad[i]){
			setans(i,q);
		}
	}
	for(int i = q-1; i > 0; i--){
		if(deactive[i] != -1){
			debug(i);
			setans(deactive[i],i);
		}
		if(remedge[i] != -1){
			pair<int,int> edge = edges[remedge[i]];
			graph[edge.F].push_back(edge.S);
			graph[edge.S].push_back(edge.F);
			if(ans[edge.F] != 0 || ans[edge.S] != 0){
				setans(edge.F,i);
				setans(edge.S,i);
			}
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
