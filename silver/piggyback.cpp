// Author: envy
// Problem: Problem 1. Piggyback
// Attempted: 2021-11-21 16:37:53 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long 
int b,e,p,n,m;
vector<int> graph[40001];

vector<int> bfs(int start){
	vector<int> dist(n+1,1e9);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int i: graph[node]){
			if(dist[i] == 1e9){
				dist[i] = dist[node]+1;
				q.push(i);
			}
		}
	}
	return dist;
	
	
}
main(){
	ifstream cin("piggyback.in");
	ofstream cout("piggyback.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>b>>e>>p>>n>>m;
	for(int i = 0; i < m; i++){
		int x,y; cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	vector<int> bes = bfs(1), els = bfs(2), fromend = bfs(n);
	int ans = 1e18;
	for(int i = 1; i <= n; i++){
		ans = min(ans,bes[i]*b+els[i]*e+p*fromend[i]);
	}
	cout<<ans;
	
}