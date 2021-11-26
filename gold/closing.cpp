// Author: envy
// Problem: Problem 2. Closing the Farm
// Attempted: 2021-11-25 15:53:19 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
vector<int> graph[200001];

struct dsu{
	vector<int> p, sz;
	
	void init(int n){
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
	
	void unite(int a, int b){
		a = get(a);
		b = get(b);
		if(sz[a] < sz[b]){
			swap(a,b);
		}
		if(a != b){
			p[b] = a;
			sz[a] += sz[b];
		}
	}
	
	bool sameset(int a, int b){
		return get(a) == get(b);
	}
	
	int getsize(int a){
		return sz[get(a)];
	}
	
};
main(){
	ifstream cin("closing.in");
	ofstream cout("closing.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;
	dsu dis;
	dis.init(n+1);
	for(int i =0; i < m; i++){
		int a,b; cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> close(n);
	vector<string> ans(n);
	vector<bool> isopen(n+1,false);
	for(int& i: close)cin>>i;
	for(int i = n-1; i >= 0; i--){
		isopen[close[i]] = true;
		for(int j: graph[close[i]]){
			if(isopen[j]){
				dis.unite(j,close[i]);
			}
		}
		
		if(dis.getsize(close[i]) == n-i){
			ans[i] = "YES";
		}
		else ans[i] = "NO";
	}
	
	for(int i = 0; i < n; i++){
		cout<<ans[i]<<endl;
	}
	
	
	
}