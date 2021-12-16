// Author: envy <3 uwu
// Problem: Problem 3. Clockwise Fence
// Attempted: 2021-12-15 19:08:49 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long

int n;
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};

bool okie(int r, int c){
	if(r < 0 || r >= 500 || c < 0 || c >= 500)return false;
	return true;
}

bool ok;

void ff(int r, int c, vector<vector<bool>>& fence, vector<vector<bool>>& visited){
	if(!ok)return;
	if(!okie(r,c)){
		ok = false;
		return;
	}
	if(visited[r][c] || fence[r][c])return;
	visited[r][c] = true;
	for(int i = 0; i < 4; i++){
		ff(dx[i]+r,dy[i]+c,fence,visited);
	}
}
void test_case(){	
	vector<vector<bool>> fence(500,vector<bool>(500,false));
	string s; cin>>s;
	n = s.length();
	int x = 250, y = 250;
	fence[x][y] = true;
	map<pair<int,int>,char> fencedir;
	
	for(int i = 0; i < n; i++){
		if(s[i] == 'S'){
			fence[x+1][y] = fence[x+2][y] = true;
			fencedir[{x+1,y}] = 'S';
			x += 2;
		}
		else if(s[i] == 'N'){
			fence[x-1][y] = fence[x-2][y] = true;
			fencedir[{x-1,y}] = 'N';
			x -= 2;
		}
		else if(s[i] == 'W'){
			fence[x][y-1] = fence[x][y-2] = true;
			fencedir[{x,y-1}] = 'W';
			y -= 2;
		}
		else if(s[i] == 'E'){
			fence[x][y+1] = fence[x][y+2] = true;
			fencedir[{x,y+1}] = 'E';
			y += 2;
		}
	}
	fence[x][y] = true;
	for(int i = 0; i < 8; i++){
		int nr = dx[i] + 250, nc = dy[i]+250;
		if(!fence[nr][nc]){
			ok = true;
			vector<vector<bool>> visited(500,vector<bool>(500,false));
			ff(nr,nc,fence,visited);
			if(ok){
				for(int i = 0; i < 500; i++){
					for(int j = 0; j < 500; j++){
						if(fencedir.count({i,j})){
							char dir = fencedir[{i,j}];
							debug(dir);
							if(visited[i][j+1]){
								if(dir == 'N'){
									cout<<"CW"<<"\n";
									return;
								}
								if(dir == 'S'){
									cout<<"CCW"<<"\n";
									return;
								}
							}
							if(visited[i][j-1]){
								if(dir == 'N'){
									cout<<"CCW"<<"\n";
									return;
								}
								if(dir == 'S'){
									cout<<"CW"<<"\n";
									return;
								}
							}
							if(visited[i+1][j]){
								if(dir == 'E'){
									cout<<"CW"<<"\n";
									return;
								}
								if(dir == 'W'){
									cout<<"CCW"<<"\n";
									return;
								}
							}
							if(visited[i-1][j]){
								if(dir == 'W'){
									cout<<"CW"<<"\n";
									return;
								}
								if(dir == 'E'){
									cout<<"CCW"<<"\n";
									return;
								}
							}
						}
					}
				}
				
				
			}
		}
		
	}
	
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		test_case();
	}
	
}
