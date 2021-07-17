// Problem: Problem 2. The Bucket List
// Contest: USACO - USACO 2018 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=856
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
	ifstream fin("blist.in");
	ofstream fout("blist.out");
	int n;
	fin>>n;
	int time[1001] = {};
	for(int i = 0; i < n; i++){
		int a,b,c;
		fin>>a>>b>>c;
		for(int j = a; j < b; j++){
			time[j] += c;
		}
	}
	sort(All(time,1001),greater<int>());
	fout<<time[0]<<endl;
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
