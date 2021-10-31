// Problem: Problem 1. Don't Be Last!
// Contest: USACO - USACO 2017 January Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=687
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// 7/18/2021 ALL TEST CASES PASSED

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



void solve(){
	ifstream fin("notlast.in");
	ofstream fout("notlast.out");
	
	map<string,int> cows;
	cows.insert({"Bessie",0});
	cows.insert({"Elsie",0});
	cows.insert({"Daisy",0});
	cows.insert({"Gertie",0});
	cows.insert({"Annabelle",0});
	cows.insert({"Maggie",0});
	cows.insert({"Henrietta",0});
	int n;
	fin>>n;
	for(int i = 0; i < n; i++){
		string cow;
		int num;
		fin>>cow>>num;
		cows[cow] += num;
	}
	vector<string> target;
	int minvalue = INF;
	
	for(auto i:cows){
		minvalue = min(i.second,minvalue);
	}
	
	int secondmin = INF;
	for(auto i:cows){
		if(i.second > minvalue)secondmin = min(secondmin,i.second);
	}
	
	for(auto i:cows){
		if(i.second == secondmin)target.pb(i.first);
	}
	
	if(target.size() > 1 || secondmin == INF)fout<<"Tie"<<endl;
	else fout<<target[0]<<endl;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
