// Problem: Problem 2. The Bovine Shuffle
// Contest: USACO - USACO 2017 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=760
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
// 7/16/2020 all test cases passed

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX
#define all(x) x.begin(), x.end() // for vectors, etc
#define All(x,l) = x, x+l; // for standard arrays, l = length
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
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");
	int n;
	fin>>n;
	int order[n];
	int cows[4][n];
	for(int i = 0; i < n; i++){
		fin>>order[i];
	}
	for(int i = 0; i < n; i++){
		fin>>cows[0][i];
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < n; j++){
			// the cow at position order[j] should move to its index
			cows[i+1][j] = cows[i][order[j]-1];
		}
	}
	for(int i = 0; i < n; i++){
		fout<<cows[3][i]<<endl;
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
