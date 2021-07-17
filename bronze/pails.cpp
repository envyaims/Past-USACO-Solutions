// Problem: Problem 1. Milk Pails
// Contest: USACO - USACO 2016 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=615
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
	ifstream fin("pails.in");
	ofstream fout("pails.out");
	int a,b,c;
	fin>>a>>b>>c;
	int maxa = c/a;
	int maxb = c/b;
	int out = 0;
	for(int i = 0; i <= maxa; i++){
		for(int j = 0; j <= maxb; j++){
			if(a*i + b*j <= c)
				out = max(out,a*i + b*j);
		}
	}
	fout<<out<<endl;
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
