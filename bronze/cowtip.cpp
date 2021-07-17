// Problem: Problem 3. Cow Tipping
// Contest: USACO - USACO 2017 January Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=689
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// ALL TEST CASES PASSED 7/17/2021

#include <bits/stdc++.h>
#include <iostream>

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
// vector<int> graph[100001]; 

void solve(){
	ifstream fin("cowtip.in");
	ofstream fout("cowtip.out");
	
	int n;
	fin>>n;
	char grid[n][n];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			fin>>grid[i][j];
		}
	}
	int output = 0;
	for(int i = n-1; i >= 0; i--){
		for(int j = n-1; j >= 0; j--){
			if(grid[i][j] == '1'){
				output++;
				for(int k = 0; k <= i; k++){
					for(int p = 0; p <= j; p++){
						if(grid[k][p] == '1')grid[k][p] = '0';
						else grid[k][p] = '1';
					}
				}
			}
			
		}
	}
	fout<<output<<endl;
	
	
	
}

int main(){
	solve();

}
