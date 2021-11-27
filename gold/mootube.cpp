// Author: envy
// Problem: Problem 1. MooTube
// Attempted: 2021-11-26 10:11:57 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
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
main(){
	ifstream cin("mootube.in");
	ofstream cout("mootube.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;
	vector<array<int,3>> edges(n-1);
	for(int i =0; i < n-1; i++){
		cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
	}
	vector<array<int,3>> qs(m);
	for(int i = 0; i < m; i++){
		cin>>qs[i][0]>>qs[i][1];
		qs[i][2] = i;
	}
	sort(qs.begin(),qs.end(),greater<array<int,3>>());
	sort(edges.begin(),edges.end(),greater<array<int,3>>());
	
	int idx = 0;
	DSU dsu(n+1);
	vector<int> ans(m);
	for(auto i: qs){
		int k = i[0];
		int v = i[1];
		while(idx < n-1 && edges[idx][0] >= k){
			dsu.unite(edges[idx][1],edges[idx][2]);
			idx++;
		}
		ans[i[2]] = dsu.getsize(v)-1;
		
	}
	for(int i: ans){
		cout<<i<<"\n";
	}
	
}