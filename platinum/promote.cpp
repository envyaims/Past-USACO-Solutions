// author: uwuenvy <3
// problem: Plat - Promotion Counting
// created: 1/26/22 12:28 PM

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int long long
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 2e5+5;
int timer = 1;
vector<int> graph[MAXN];
int st[MAXN], en[MAXN];

void dfs(int node, int p){
    st[node] = timer++;
    for(int i: graph[node]){
        if(i != p)
            dfs(i,node);
    }
    en[node] = timer++;
}

void solve() {
    int n; cin>>n;
    vector<pair<int,int>> val;
    for(int i = 1; i <= n; i++){
        int v; cin>>v;
        val.emplace_back(v,i);
    }
    sort(val.rbegin(),val.rend());
    for(int i = 2; i <= n; i++){
        int v; cin>>v;
        graph[v].push_back(i);
    }
    dfs(1,0);

	ordered_set<int> oset;
	vector<int> ans(n+1);
	for(auto i: val){
		ans[i.second] = oset.order_of_key(en[i.second]) - oset.order_of_key(st[i.second]);
		oset.insert(st[i.second]);
	}
	for(int i = 1; i <= n; i++){
		cout<<ans[i]<<"\n";
	}

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("promote.in","r",stdin);
	freopen("promote.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}



