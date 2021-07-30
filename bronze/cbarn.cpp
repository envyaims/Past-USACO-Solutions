// Problem: Problem 2. Circular Barn
// Contest: USACO - USACO 2016 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=616
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file cbarn.in  
// Output: file cbarn.out  
// Attempted: 2021-07-30 08:56:49 EST
// all test cases passed

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
	ifstream cin("cbarn.in");
	ofstream cout("cbarn.out");
	int n;
	cin>>n;
	vector<int> rooms(n);
	for(int i = 0; i < n; i++){
		cin>>rooms[i];
	}
	
	int ans = INT_MAX;
	
	for(int i = 0; i < n; i++){
		rotate(rooms.begin(),rooms.begin()+1,rooms.end());
		int tempans = 0;
		for(int j = 0; j < n; j++){
			tempans += (j * rooms[j]);
		}
		ans = min(tempans,ans);
	}
	print(ans);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
