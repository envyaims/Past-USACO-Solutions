// Author: envy <3 uwu
// Problem: Problem 3. Acowdemia III
// Attempted: 2021-12-14 22:20:23 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
int n,m;
bool notb(int r, int c){
	if(r >= n || r < 0 || c >= m || c < 0)return false;
	return true;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	char grid[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>grid[i][j];
		}
	}
	set<pair<int,int>> cows;
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 'G'){
				vector<pair<int,int>> ps;
				for(int k = 0; k < 4; k++){
					int nr = dx[k]+i, nc = dy[k]+j;
					if(notb(nr,nc) && grid[nr][nc] == 'C'){
						ps.push_back({nr,nc});
					}
				}
				if(ps.size() > 2){
					ans++;
				}
				else if(ps.size() == 2){
					int id1 = ps[0].first*1000+ps[0].second;
					int id2 = ps[1].first*1000+ps[1].second;
					cows.insert((pair<int,int>){min(id1,id2),max(id1,id2)});
				}
			}
		}
	}
	printf("%lld",cows.size()+ans);
	
	
}
