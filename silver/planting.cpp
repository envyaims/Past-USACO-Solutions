// Problem: Problem 1. Grass Planting
// Contest: USACO - USACO 2019 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=894
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// ALL TEST CASES PASSED 7/17/2021

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

vector<int> graph[100001]; 
void solve(){
	ifstream fin("planting.in");
	ofstream fout("planting.out");
	int n;
	fin>>n;
	for(int i = 0; i < n-1; i++){
		int a,b;
		fin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	ll output = 0;
	for(int i = 0; i < 100001; i++){
		if(graph[i].size() > output)output = graph[i].size();
	}
	fout<<output+1<<endl;
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
