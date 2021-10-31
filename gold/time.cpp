// Author: envy
// Problem: Problem 1. Time is Mooney from USACO - USACO 2020 January Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=993
// Limits: 4000 ms, 256 MB
// Attempted: 2021-10-31 07:34:17 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
main(){
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,c; cin>>n>>m>>c;
	vector<int> moners(n+1);
	for(int i = 1; i <= n; i++){
		cin>>moners[i];
	}
	vector<vector<int>> graph(n+1);
	for(int i = 0; i < m; i++){
		int a,b; cin>>a>>b;
		graph[a].push_back(b);
	}
	vector<vector<int>> dp(1001,vector<int>(1001,-1));
	// dp[node][day]
	dp[1][0] = moners[1];
	
	queue<int> q;
	q.push(1);
	for(int day = 1; day <= 1000; day++){
		set<int> donext;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(int i: graph[node]){
				dp[i][day] = max(dp[i][day], dp[node][day-1] + moners[node]);
				donext.insert(i);
			}
		}
		for(int i: donext){
			q.push(i);
		}
	}
	int ans = 0;
	for(int i = 0; i <= 1000; i++){
		ans = max(ans, dp[1][i] - c * i * i);
	}
	cout<<ans;
	
}