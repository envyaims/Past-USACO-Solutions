// Problem: Problem 2. Bovine Genomics
// Contest: USACO - USACO 2017 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=736
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// ALL TEST CASES PASSED 7/16/2021

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX
#define all(x) x.begin(), x.end() // for vectors, etc
#define All(x,l) x, x+l // for standard arrays, l = length
#define pb(x) push_back(x);
#define debug(x) fout<<#x<<" = "<<x<<endl
#define print(x) fout<<x<<endl
#define mp(x,y) make_pair(x,y)

template<typename T>
vector<string> split(T str, char sep){
	vector<string> output;
	size_t start = 0, end = 0;
	while((end = str.find(sep,start)) != string::npos){
		if(end != start)output.pb(str.substr(start,end-start));
		start = end+1;
	}
	
	if(end != start)output.pb(str.substr(start));
	return output;
	
}


void solve(){
	ifstream fin("cownomics.in");
	ofstream fout("cownomics.out");
	int n,m;
	fin>>n>>m;
	string spot[n];
	string nospot[n];
	for(int i = 0; i < n; i++){
		fin>>spot[i];
	}
	for(int i = 0; i < n; i++){
		fin>>nospot[i];
	}
	
	int output = 0;
	
	for(int i = 0; i < m; i++){
		set<char> spothave;
		bool cond = true;
		for(int j = 0; j < n; j++){
			spothave.insert(spot[j][i]);
		}
		for(int j = 0; j < n; j++){
			if(spothave.find(nospot[j][i]) != spothave.end()){
				cond = false;
				break;
			}
		}
		if(cond)output++;
	}
	fout<<output;
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
