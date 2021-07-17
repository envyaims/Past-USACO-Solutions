// Problem: Problem 3. Livestock Lineup
// Contest: USACO - USACO 2019 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=965
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// ALL TEST CASES PASSED. 7/17/2021

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
	ifstream fin("lineup.in");
	ofstream fout("lineup.out");
	int n;
	fin>>n;
	vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", 
	"Blue", "Betsy", "Sue"};
	sort(all(cows));
	vector<pair<string,string>> cond;
	for(int i = 0; i < n; i++){
		string in;
		while(getline(fin,in)){
			if(!in.empty())break;
		}
		vector<string> firstlast = split<string>(in,' ');
		cond.pb(mp(firstlast[0],firstlast[firstlast.size()-1]));
		
	}
	while(next_permutation(all(cows))){
		int satisfied = 0;
		for(int i = 0; i < n; i++){
			auto it = find(all(cows),cond[i].first);
			auto it2 = find(all(cows),cond[i].second);
			if(abs((it - cows.begin())-(it2 - cows.begin())) == 1)satisfied++;
		}
		if(satisfied == n)break;
	}
	for(string i:cows){
		fout<<i<<endl;
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
