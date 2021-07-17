// Problem: Problem 1. Censoring (Bronze)
// Contest: USACO - USACO 2015 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=526
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX
#define all(x) x.begin(), x.end() // for vectors, etc
#define All(x,l) = x, x+l; // for standard arrays
#define pb(x) push_back(x);
#define debug(x) cout<<#x<<" = "<<x<<endl
#define print(x) cout<<x<<endl
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
	ifstream fin("censor.in");
	ofstream fout("censor.out");
	string init,del;
	getline(fin,init);
	getline(fin,del);
	while(init.find(del) != string::npos){
		int ind = init.find(del);
		init = init.substr(0, ind) + init.substr(ind+del.length());
	}
	fout<<init<<endl;
	 
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
