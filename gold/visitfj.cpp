// Author: envy
// Problem: Problem 1. Why Did the Cow Cross the Road from USACO - USACO 2017 February Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=717
// Limits: 4000 ms, 256 MB
// Attempted: 2021-10-30 20:38:53 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long

int grid[100][100];
int n,t;
bool visited[100][100][3];
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;


main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ifstream cin("visitfj.in");
	ofstream cout("visitfj.out");
	cin>>n>>t;
	for(int i= 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>grid[i][j];
		}
	}
	minpq<array<int,4>> pq;
	pq.push({0,0,0,0});
	// [total dist, steps, row, col]
	int ans =0;
	while(!pq.empty()){
		array<int,4> front = pq.top();
		pq.pop();
		int distance = front[0], steps = front[1], row = front[2], col = front[3];
		if(visited[row][col][steps%3]){
			continue;
		}
		visited[row][col][steps%3] = true;
		if(row == n-1 and col == n-1){
			cout<<distance;
			break;
		}
		
		for(int i = 0; i < 4; i++){
			int r = dx[i] + row, c = dy[i] + col;
			if(r < 0 || r >= n || c < 0 || c >= n)continue;
			int add = grid[r][c] * (steps%3==2) + t;
			pq.push({distance+add, steps+1,r,c});
		}
		
	}


	
}
