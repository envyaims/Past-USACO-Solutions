#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
vector<int> g[N];
int friends[N];
bool vis[N];
struct DSU{
	vector<int> p, sz;
	vector<multiset<int>> deg;
	DSU(int n){
		p.resize(n);
		sz.resize(n,1);
		deg.resize(n);
		for(int i = 0; i < n; i++){
			deg[i].insert(0);
		}
		iota(p.begin(),p.end(),0);
	}
	int get(int x){
		if(p[x] != x){
			p[x] = get(p[x]);
		}
		return p[x];
	}
	bool unite(int a, int b){
		a = get(a); b = get(b);
		if(sz[a] < sz[b])swap(a,b);
		if(a != b){
			p[b] = a;
			sz[a] += sz[b];
			for(int i: deg[b]) deg[a].insert(i);
		}
		return a != b;
	}
	int get_min(int a){
		return *deg[get(a)].begin();
	}
	int getsize(int a){return sz[get(a)];}
};
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int n,m; cin >> n >> m;
	DSU dsu(n);
	vector<pair<int, int>> edges;
	for(int i = 0; i < m; i++){
		int u,v; cin >> u >> v;
		--u; --v;
		dsu.unite(u, v);
		friends[u]++; friends[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<vector<int>> comp(n);
	for(int i = 0; i < n; i++) comp[dsu.get(i)].push_back(i);
	DSU dsu2(n);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		minpq<pair<int, int>> pq;
		for(int j: comp[i]) pq.push({friends[j], j});
		vector<pair<int,int>> order;
		while(!pq.empty()){
			auto [e, x] = pq.top();
			pq.pop();
			if(vis[x]) continue;
			assert(e == friends[x]);
			vis[x] = true;
			friends[x] = 0;
			for(int j: g[x]){
				if(!vis[j]){
					order.push_back({x, j});
					--friends[j];
					pq.push({friends[j], j});
				}
			}
		}
		reverse(order.begin(), order.end());
		for(auto e: order){
			dsu2.deg[dsu2.get(e.first)].erase(dsu2.deg[dsu2.get(e.first)].find(friends[e.first]));
			dsu2.deg[dsu2.get(e.second)].erase(dsu2.deg[dsu2.get(e.second)].find(friends[e.second]));
			dsu2.deg[dsu2.get(e.first)].insert(++friends[e.first]);
			dsu2.deg[dsu2.get(e.second)].insert(++friends[e.second]);
			dsu2.unite(e.first, e.second);
			ans = max(ans, (ll)dsu2.getsize(e.first) * dsu2.get_min(e.first));
		}
		
	}
	cout << ans << endl;
	
	
}
