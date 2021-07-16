// Problem: Problem 2. Speeding Ticket
// Contest: USACO - USACO 2015 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=568
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	ifstream fin("speeding.in");
	ofstream fout("speeding.out");
	int n,m;
	fin>>n>>m;
	int bess[100];
	int road[100];
	
	int pre = 0;
	for(int i = 0; i < n; i++){
		int distance, limit;
		fin>>distance>>limit;
		for(int i = pre; i < pre+distance; i++){
			road[i] = limit;
		}
		pre += distance;
	}
	
	int apre = 0;
	for(int i = 0; i < n; i++){
		int distance, limit;
		fin>>distance>>limit;
		for(int i = apre; i < apre+distance; i++){
			bess[i] = limit;
		}
		apre += distance;
	}
	int output = 0;
	for(int i = 0; i < 100; i++){
		output = max(output,bess[i] - road[i]);
	}
	fout<<output<<endl;
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
