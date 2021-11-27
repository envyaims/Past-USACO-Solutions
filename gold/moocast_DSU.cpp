// Author: envy
// Problem: Problem 1. Moocast
// Attempted: 2021-11-26 10:44:37 EST

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
	ifstream cin("moocast.in");
	ofstream cout("moocast.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<pair<int,int>> cows(n);
	for(int i = 0; i < n; i++){
		cin>>cows[i].first>>cows[i].second;
	}
	vector<array<int,3>> edges;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int dist = (cows[i].first - cows[j].first)*(cows[i].first - cows[j].first)+(cows[i].second - cows[j].second)*(cows[i].second - cows[j].second);
			edges.push_back({dist,i,j});
		}
	}
	sort(edges.begin(),edges.end());
	DSU dsu(n);
	for(auto i: edges){
		if(dsu.unite(i[1],i[2]) && dsu.getsize(0) == n){
			cout<<i[0];
			return 0;
		}
	}
	
}