// Problem: Problem 1. Sleepy Cow Herding
// Contest: USACO - USACO 2019 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=915
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	ifstream fin("herding.in");
	ofstream fout("herding.out");
	int a,b,c;
	fin>>a>>b>>c;
	vector<int> cows = {a,b,c};
	sort(all(cows));
	int ba = cows[1] - cows[0];
	int cb = cows[2] - cows[1];
	if(ba == 1 && cb == 1){
		fout<<0<<endl;
		fout<<0<<endl;
	}
	else if(min(ba,cb) == 2){
		fout<<1<<endl;
		fout<<max(ba,cb)-1<<endl;
	}
	else{
		fout<<2<<endl;
		fout<<max(ba,cb)-1<<endl;
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
