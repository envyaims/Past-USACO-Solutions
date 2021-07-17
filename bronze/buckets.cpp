// Problem: Problem 1. Bucket Brigade
// Contest: USACO - USACO 2019 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=939
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// ALL TEST CASES PASSED 7/17/2021

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
	ifstream fin("buckets.in");
	ofstream fout("buckets.out");
	pair<int,int> barn;
	pair<int,int> lake;
	pair<int,int> rock;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			char in;
			fin>>in;
			if(in == 'B') barn = mp(i,j);
			else if(in == 'L') lake = mp(i,j);
			else if(in == 'R') rock = mp(i,j);
		}
	}
	
	int rl = abs(lake.second-rock.second) + abs(lake.first-rock.first);
	int br = abs(barn.second-rock.second) + abs(barn.first-rock.first);
	int bl = abs(lake.second-barn.second) + abs(lake.first-barn.first);
	int distance = 0;
	
	if((barn.first == lake.first || barn.second == lake.second) && bl == (rl+br)){
		distance = bl+1;
	}
	else distance = bl-1;
	
	fout<<distance<<endl;
	
	
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
