// Problem: Problem 1. Blocked Billboard
// Contest: USACO - USACO 2017 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=759
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// ALL TEST CASES PASSED, 7/16/2021

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX
#define fl(i,n) for(i = 0; i < n; i++)
#define all(x) x.begin(), x.end() // for vectors, etc
#define All(x,l) = x, x+l; // for standard arrays
#define pb(x) push_back(x);
#define debug(x) fout<<#x<<" = "<<x<<endl
#define print(x) fout<<x<<endl

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

int area(vector<int> pts){
	return (pts[2] - pts[0])* (pts[3] - pts[1]);
}

int intersect(vector<int> a, vector<int> b){
	int overlapx = max(0, min(a[2], b[2]) - max(a[0], b[0]));
	int overlapy = max(0, min(a[3], b[3]) - max(a[1], b[1]));
	return overlapx * overlapy; // overlapping area
	
}
void solve(){
	ifstream fin("billboard.in");
	ofstream fout("billboard.out");
	vector<int> fir(4);
	vector<int> sec(4);
	vector<int> block(4);
	for(int i = 0; i < 4; i++){
		fin>>fir[i];
	}
	for(int i = 0; i < 4; i++){
		fin>>sec[i];
	}
	for(int i = 0; i < 4; i++){
		fin>>block[i];
	}
	
	fout<<area(fir) + area(sec) - intersect(fir,block) - intersect(sec,block) << endl;
	
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
