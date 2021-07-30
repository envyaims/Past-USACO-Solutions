// Problem: Problem 1. Uddered but not Herd
// Contest: USACO - USACO 2021 January Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=1083
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
//ALL TEST CASES PASSED. 7/17/2021

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX
#define all(x) x.begin(), x.end() // for vectors, etc
#define All(x,l) x, x+l // for standard arrays, l = length
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<endl
#define print(x) cout<<x<<endl
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
	string order, hear;
	cin>>order>>hear;
	
	int output = 1;
	int pointindex = 0;
	for(char i: hear){
		if(order.find(i) <= pointindex){
			output++;
			pointindex = order.find(i);
		}
		else{
			pointindex = order.find(i);
		}
	}
	print(output);
	
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
