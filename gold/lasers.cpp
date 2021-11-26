// Author: envy
// Problem: Problem 3. Lasers and Mirrors
// Attempted: 2021-11-21 17:08:01 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
main(){
	ifstream cin("lasers.in");
	ofstream cout("lasers.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<pair<int,int>> pts(n+2);
	unordered_map<int,vector<int>> vert, hori;
	
	for(int i = 0; i < n+2; i++){
		cin>>pts[i].first>>pts[i].second;
		vert[pts[i].first].push_back(i);
		hori[pts[i].second].push_back(i);
		
	}
	vector<int> dist(n+2,1e9);
	// 0 point is start, 1 point is end;
	queue<pair<int, char>> q;
	q.push({0,'H'});
	q.push({0,'V'});
	dist[0] = 0;
	while(!q.empty()){
		pair<int, char> curr = q.front();
		q.pop();
		if(curr.second == 'V'){
			for(int i: vert[pts[curr.first].first]){
				if(dist[i] == 1e9){
					dist[i] = dist[curr.first]+1;
					q.push({i,'H'});
				}
			}
		}
		else{
			for(int i: hori[pts[curr.first].second]){
				if(dist[i] == 1e9){
					dist[i] = dist[curr.first]+1;
					q.push({i,'V'});
				}
			}
		}
	}
	
	if(dist[1] == 1e9)cout<<-1;
	else cout<<dist[1]-1;
	
}