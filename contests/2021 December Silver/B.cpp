#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DSU{
	vector<int> p, sz;
	DSU(int n){
		p.resize(n);
		sz.resize(n,1);
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
		}
		return a != b;
	}
	bool sameset(int a, int b){return get(a) == get(b);}
	int getsize(int a){return sz[get(a)];}
};


void test_case(){
	int n,m;
	cin>>n>>m;
	DSU dsu(n+1);
	for(int i = 0; i < m; i++){
		int a,b; cin>>a>>b;
		dsu.unite(a,b);
	}
	vector<vector<int>> comp(n+1);
	for(int i = 1; i <= n; i++){
		comp[dsu.get(i)].push_back(i);
	}
	
	auto mindif = [&](int a, int b){
		int final = 1e9;
		for(int i: comp[a]){
			auto it = lower_bound(comp[b].begin(),comp[b].end(),i);
			if(it != comp[b].end()){
				final = min(final,*it-i);
			}
			if(it != comp[b].begin()){
				it--;
				final = min(final,i-*it);
			}
		}
		
		return final;
	};
	int ans = mindif(dsu.get(1),dsu.get(n));
	int onecmp = dsu.get(1), lastcmp = dsu.get(n);
	for(int i = 1; i <= n; i++){
		if(i != onecmp && i != lastcmp && !comp[i].empty()){
			int ff = mindif(onecmp,i), ss = mindif(i,lastcmp);
			ans = min(ans,ff*ff+ss*ss);
		}
	}
	printf("%lld\n",ans);
	
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		test_case();
	}
	
	
}