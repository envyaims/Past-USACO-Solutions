// Author: envy
// Problem: Problem 3. Superbull
// Attempted: 2021-11-25 22:40:19 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
int ans = 0;
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
	void unite(int a, int b, int curr){
		a = get(a); b = get(b);
		if(sz[a] < sz[b])swap(a,b);
		if(a != b){
			p[b] = a;
			sz[a] += sz[b];
			ans += curr;
		}
	}
	bool sameset(int a, int b){return get(a) == get(b);}
	int getsize(int a){return sz[get(a)];}
};
main(){
	ifstream cin("superbull.in");
	ofstream cout("superbull.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<int> ids(n);
	for(int& i: ids)cin>>i;
	vector<array<int,3>> edges;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			edges.push_back({(ids[i] ^ ids[j]),i,j});
		}
	}
	sort(edges.begin(),edges.end(),greater<array<int,3>>());
	DSU dsu(n);
	for(auto i: edges){
		dsu.unite(i[1],i[2],i[0]);
	}
	cout<<ans;
	
	
}