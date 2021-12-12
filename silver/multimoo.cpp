// Author: envy <3 uwu
// Problem: Problem 3. Multiplayer Moo
// Attempted: 2021-12-12 10:05:23 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
struct DSU{
	vector<int> p, sz;
	DSU(int n){
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
	bool unite(int a, int b){
		a = get(a); b = get(b);
		if(sz[a] < sz[b])swap(a,b);
		if(a != b){
			p[b] = a;
			sz[a] += sz[b];
		}
		return a != b;
	}
	bool sameset(int a, int b){return get(a) == get(b);}
	int getsize(int a){return sz[get(a)];}
};
int n;
int grid[250][250], id[250][250];
bool visited[250][250];
map<int,set<int>> adj[100001];
vector<bool> visited2(100001);
DSU dsu(100001);
int idtoval[100001];
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

void ff(int r, int c){
	for(int i = 0; i < 4; i++){
		int nr = dx[i]+r, nc = dy[i]+c;
		if(nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc])continue;
		if(grid[nr][nc] == grid[r][c]){
			visited[r][c] = true;
			dsu.unite(id[r][c],id[nr][nc]);
			ff(nr,nc);
		}
	}
}

void dfs(int curid, int col1, int col2, int& sum){
	if(visited2[curid])return;
	visited2[curid] = true;
	sum += dsu.getsize(curid);
	if(idtoval[curid] == col1){
		for(int i: adj[curid][col2]){
			dfs(i,col1,col2,sum);
		}
	}
	else{
		for(int i: adj[curid][col1]){
			dfs(i,col1,col2,sum);
		}
	}
}

main(){
	ifstream cin("multimoo.in");
	ofstream cout("multimoo.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>grid[i][j];
			id[i][j] = n*i+j;
			idtoval[id[i][j]] = grid[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]){
				visited[i][j] = true;
				ff(i,j);
			}
		}
	}
	
	int one = 0, two = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int cursize = dsu.getsize(id[i][j]);
			one = max(one,cursize);
			
			int cur = grid[i][j];
			if(i < n-1){
				int nxt = grid[i+1][j];
				if(cur != nxt){
					adj[dsu.get(id[i][j])][nxt].insert(dsu.get(id[i+1][j]));
					adj[dsu.get(id[i+1][j])][cur].insert(dsu.get(id[i][j]));
				}
			}
			if(j < n-1){
				int nxt = grid[i][j+1];
				if(cur != nxt){
					adj[dsu.get(id[i][j])][nxt].insert(dsu.get(id[i][j+1]));
					adj[dsu.get(id[i][j+1])][cur].insert(dsu.get(id[i][j]));
				}
			}
		}
	}
	for(int i = 0; i <= 100000; i++){
		for(auto j: adj[i]){
			fill(visited2.begin(), visited2.end(),false);
			int sum = 0;
			dfs(i, idtoval[i], j.first,sum);
			two = max(two,sum);
			
		}
	}
	cout<<one<<"\n"<<two;
	
}
