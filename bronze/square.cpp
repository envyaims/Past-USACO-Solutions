// Problem: Problem 1. Square Pasture
// Contest: USACO - USACO 2016 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=663
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
// ALL TEST CASES PASSED, 7/16/2021

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX
#define all(x) x.begin(), x.end() // for vectors, etc
#define All(x,l) = x, x+l; // for standard arrays
#define pb(x) push_back(x);
#define debug(x) cout<<#x<<" = "<<x<<endl
#define print(x) cout<<x<<endl

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
	ifstream fin("square.in");
	ofstream fout("square.out");
	vector<int> a(4);
	vector<int> b(4);
	for(int i = 0; i < 4; i++){
		fin>>a[i];
	}
	
	for(int i = 0; i < 4; i++){
		fin>>b[i];
	}
	
	int reach = max(max(a[2],b[2]) - min(a[0],b[0]),max(a[3],b[3]) - min(a[1],b[1]));
	fout<<reach*reach<<endl;
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
