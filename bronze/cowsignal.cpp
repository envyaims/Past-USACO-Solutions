// Problem: Problem 3. The Cow-Signal
// Contest: USACO - USACO 2016 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=665
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
// ALL TEST CASES PASSED, 7/16/2021

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
	ifstream fin("cowsignal.in");
	ofstream fout("cowsignal.out");
	int row,col,k;
	fin>>row>>col>>k;
	char init[row][col];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			fin>>init[i][j];
		}
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < k; j++){
				for(int fillrow = 0; fillrow < col; fillrow++){
					for(int fillcol = 0; fillcol < k; fillcol++){
						fout<<init[i][fillrow];
						
					}
				}
				fout<<endl;
				
			}
		}

	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
