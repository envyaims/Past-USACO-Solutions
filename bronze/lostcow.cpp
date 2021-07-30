// Problem: Problem 1. The Lost Cow
// Contest: USACO - USACO 2017 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=735
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file lostcow.in  
// Output: file lostcow.out  
// Attempted: 2021-07-30 10:49:13 EST
// ALL TEST CASES PASSED

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pi;

const ll INF = 1e18;
const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<endl
#define print(x) cout<<x<<endl
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())


void doStuff(){
	ifstream cin("lostcow.in");
	ofstream cout("lostcow.out");
	int x,y; cin>>x>>y;
	int steps = 0;
	
	bool behind = false;
	if(x < y)behind = true;
	
	
	for(int i = 0; i < 100; i++){
		if(i % 2 == 0){
			steps += (pow(2,i) + pow(2,i-1));
			if(x + pow(2,i) >= y && behind){
				steps -= ((x + pow(2,i)) - y);
				break;
			}
		}
		else{
			steps += (pow(2,i) + pow(2,i-1));
			if(x - pow(2,i) <= y && !behind){
				steps -= (y - (x - pow(2,i)));
				break;
			}
		}
	}
	
	
	print(steps);
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
