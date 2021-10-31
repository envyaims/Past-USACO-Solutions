// Author: envy
// Problem: Problem 1. Milk Pumping from USACO - USACO 2019 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=969
// Limits: 4000 ms, 256 MB
// Attempted: 2021-10-31 08:18:42 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
#define mp make_pair
#define F first
#define S second


main(){
	freopen("pump.in","r",stdin);
	freopen("pump.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;
	vector<vector<int>> graph(n+1);
	map<pair<int,int>,int> cost, flow;
	for(int i = 0; i < m; i++){
		int a,b,c,d; cin>>a>>b>>c>>d;
		graph[a].push_back(b);
		graph[b].push_back(a);
		cost[mp(a,b)] = c;
		cost[mp(b,a)] = c;
		flow[(mp(a,b))] = d;
		flow[(mp(b,a))] = d;
	}
	
	priority_queue<pair<double,array<int,3>>> pq;
	vector<bool> visited(n+1);
	// pair(cost/flow, {cost,flow,node})
	pq.push(mp(0,(array<int,3>){0,-100000000,1}));
	double ans = -1e9;
	while(!pq.empty()){
		pair<double,array<int,3>> front = pq.top();
		double ratio = front.F;
		int node = front.S[2];
		int costi = front.S[0];
		int flowi = front.S[1] * -1;
		pq.pop();
		if(visited[node]){
			continue;
		}
		visited[node] = true;
		if(node == n){
			ans = max(ans,ratio);
			continue;
		}
		for(int i: graph[node]){
			int newcost = costi + cost[mp(node,i)];
			int newflow = min(flowi,flow[mp(node,i)]);
			double newratio = newflow*1.00/newcost;
			pq.push(mp(newratio,(array<int,3>){newcost,-newflow,i}));
		}
		
	}
	stringstream ss;
	ss<<setprecision(7)<<ans*1000000;
	cout<<stoi(ss.str());
	
	
}
