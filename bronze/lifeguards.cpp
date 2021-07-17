// Problem: Problem 2. Lifeguards
// Contest: USACO - USACO 2018 January Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=784
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
#define debug(x) fin<<#x<<" = "<<x<<endl
#define print(x) fin<<x<<endl
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
	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");
	int n;
	int time[1001] = {};
	int output = 0;
	vector<pair<int,int>> timespan;
	fin>>n;
	for(int i = 0; i < n; i++){
		int lower,upper;
		fin>>lower>>upper;
		timespan.pb(mp(lower,upper));
		for(int j = lower; j < upper; j++){
			time[j] += 1;
		}
	}
	
	for(int i = 0; i < n; i++){
		int low = timespan[i].first;
		int high = timespan[i].second;
		int temptime[1001];
		int tempout = 0;
		copy(begin(time),end(time),begin(temptime));
		for(int i = low; i < high; i++){
			temptime[i] -=1;
		}
		for(int i:temptime){
			if(i > 0)tempout++;
		}
		output = max(output,tempout);
		
	}
	
	fout<<output;
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
