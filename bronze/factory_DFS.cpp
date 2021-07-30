// Problem: Problem 2. Milk Factory
// Contest: USACO - USACO 2019 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=940
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// DFS PROBLEM
// 8/10 TEST CASES PASSED 7/17/2021

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX
#define all(x) x.begin(), x.end() // for vectors, etc
#define All(x,l) x, x+l // for standard arrays, l = length
#define pb(x) push_back(x)
#define debug(x) fout<<#x<<" = "<<x<<endl
#define print(x) fout<<x<<endl
#define mp(x,y) make_pair(x,y)
#define cpy(x,y) copy(begin(x),end(x),begin(y)) // copy standard arrays x -> y

vector<int> graph[102];
bool visited[102] = {0};

void dfs(int node){
	if(visited[node])return;
	
	visited[node] = true;	
	for(auto i: graph[node]){
		if(!visited[i]) dfs(i);
	} 
}
void solve(){
	ifstream fin("factory.in");
	ofstream fout("factory.out");
	int n;
	fin>>n;
	for(int i = 0; i < n-1; i++){
		int a,b;
		fin>>a>>b; 
		graph[b].pb(a); // INITIALIZE GRAPH (one directional)
	}
	int output = -1;
	for(int i = 1; i <= n; i++){
		dfs(i);
		bool done = true;
		for(int i = 1; i <= n; i++){
			if(visited[i] == false)done = false;
		}
		if(done){
			output = i;
			break;
		}
	}
	fout<<output<<endl;
	
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
	
    

    return 0;
}
