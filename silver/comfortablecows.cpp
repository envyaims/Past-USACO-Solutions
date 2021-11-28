// Author: envy
// Problem: Problem 1. Comfortable Cows
// Attempted: 2021-11-28 17:21:45 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
int ans = 0;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
bool grid[3000][3000];

void add(int x, int y);

void check(int x, int y){
	if(!grid[x][y])return;
	vector<pair<int,int>> no;
	for(int i = 0; i < 4; i++){
		if(!grid[dx[i]+x][dy[i]+y]){
			no.push_back({dx[i]+x,dy[i]+y});
		}
	}
	if(no.size() == 1){
		ans++;
		add(no[0].first,no[0].second);
	}
}

void add(int x, int y){
	grid[x][y] = true;
	check(x,y);
	for(int i = 0; i < 4; i++){
		check(dx[i]+x,dy[i]+y);
	}
}
main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q; cin>>q;
	while(q--){
		int x,y; cin>>x>>y;
		x += 1000; y += 1000;
		if(grid[x][y]){
			ans--;
		}
		else{
			add(x,y);
		}
		cout<<ans<<"\n";
	}
	
	
}
