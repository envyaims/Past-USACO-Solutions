// Problem: Problem 3. Swapity Swap
// Contest: USACO - USACO 2020 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=1013
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// 7/13 CASES PASSED. REST TLE. 7/17/2021	

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
	ifstream fin("swap.in");
	ofstream fout("swap.out");
	int n,k;
	fin>>n>>k;
	vector<int> cows(n);
	for(int i =1; i <= n; i++){
		cows[i-1] = i;
	}
	int a,b;
	fin>>a>>b;
	pair<int,int> rev1 = mp(a-1,b);
	int c,d;
	fin>>c>>d;
	pair<int,int> rev2 = mp(c-1,d);
	
	for(int i = 0; i < k; i++){
		reverse(cows.begin() + rev1.first, cows.begin() + rev1.second);
		reverse(cows.begin() + rev2.first, cows.begin() + rev2.second);
	}
	
	for(int i: cows){
		fout<<i<<endl;
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
