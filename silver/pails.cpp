// Author: envy
// Problem: Problem 3. Milk Pails
// Attempted: 2021-11-20 22:23:43 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
main(){
	ifstream cin("pails.in");
	ofstream cout("pails.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y,k,m; cin>>x>>y>>k>>m;
	vector<vector<int>> dist(x+1,vector<int>(y+1,1e9));
	queue<pair<int,int>> q;
	dist[0][0] = 0;
	q.push({0,0});
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		int curr = dist[top.first][top.second];
		if(curr == k)continue;
		
		if(dist[x][top.second] == 1e9){
			dist[x][top.second] = curr+1;
			q.push({x,top.second});
		}
		if(dist[top.first][y] == 1e9){
			dist[top.first][y] = curr+1;
			q.push({top.first,y});
		}
		if(dist[0][y] == 1e9){
			dist[0][y] = curr+1;
			q.push({0,y});
		}
		if(dist[x][0] == 1e9){
			dist[x][0] = curr+1;
			q.push({x,0});
		}
		int pour = min(top.first,y-top.second);
		if(dist[top.first - pour][top.second + pour] == 1e9){
			dist[top.first-pour][top.second+pour] = curr+1;
			q.push({top.first-pour,top.second+pour});
		}
		
		pour = min(top.second, x-top.first);
		if(dist[top.first+pour][top.second-pour] == 1e9){
			dist[top.first+pour][top.second-pour] = curr+1;
			q.push({top.first+pour,top.second-pour});
		}
	}
	int ans = 1e9;
	for(int i = 0; i <= x; i++){
		for(int j = 0; j <= y; j++){
			if(dist[i][j] != 1e9){
				ans = min(ans,abs(i+j-m));
			}
		}
	}
	cout<<ans;	
}