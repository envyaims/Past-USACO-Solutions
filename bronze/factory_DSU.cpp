// Author: envy
// Problem: Problem 2. Milk Factory
// Attempted: 2021-11-27 22:01:59 EST

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
	int get(int x){return p[x]!=x?p[x]=get(p[x]):p[x];}
	bool unite(int a, int b){
		a = get(a); b = get(b);
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
	freopen("factory.in","r",stdin);
	freopen("factory.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	DSU dsu(n+1);
	vector<int> deg(n+1);
	for(int i = 0; i < n-1; i++){
		int a,b; cin>>a>>b;
		dsu.unite(b,a);
		deg[a]++;
	}
	dsu.getsize(dsu.get(1))==n&&count(deg.begin(),deg.end(),0)==2?cout<<dsu.get(1):cout<<-1;
}
