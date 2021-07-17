// Problem: Problem 3. Clockwise Fence
// Contest: USACO - USACO 2021 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=1109
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

int crossproduct(pair<int,int> p1, pair<int,int> p2){
	return p1.first * p2.second - p2.first * p1.second;
}


void solve(){
	int n;
	cin>>n;
	for(int test = 0; test < n; test++){
		string path;
		cin>>path;
		pair<int,int> location = mp(0,0);
		int output = 0;
		for(char i: path){
			pair<int, int> newlocation;
			if(i == 'N')newlocation = mp(location.first,location.second+1);
			else if(i == 'S')newlocation = mp(location.first,location.second-1);
			else if(i == 'W')newlocation = mp(location.first-1,location.second);
			else if(i == 'E')newlocation = mp(location.first+1,location.second);
			output += crossproduct(newlocation,location);
			location = newlocation;
		}
		if(output > 0)print("CW");
		else print("CCW");
		
		
		
	}
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
