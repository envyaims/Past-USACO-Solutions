// Problem: Problem 1. Fence Painting
// Contest: USACO - USACO 2015 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=567
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// 7/15/2021 ALL TEST CASES PASSED

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX
#define fl(i,n) for(i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
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
	ifstream fin("paint.in");
	ofstream fout("paint.out");
	vector<int> temp(4);
	for(int i = 0; i < 4; i++){
		fin>>temp[i];
	}
	if((temp[3] >= temp[0] && temp[0] >= temp[2]) || temp[2] > temp[0] && temp[1] >= temp[2]){ // check if overlapping
		sort(all(temp));
		fout<<temp[3] - temp[0]<<endl;
		}
		
	else fout<<(temp[1] - temp[0]) + (temp[3]) - temp[2]<<endl;
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
