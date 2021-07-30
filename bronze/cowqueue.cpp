// Problem: Problem 3. Why Did the Cow Cross the Road III
// Contest: USACO - USACO 2017 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=713
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file cowqueue.in  
// Output: file cowqueue.out  
// Attempted: 2021-07-30 18:50:02 EST
// all test cases passwed we gucci

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pi;

const int INF = 1e18, MOD = 1e9+7;
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
	ifstream cin("cowqueue.in");
	ofstream cout("cowqueue.out");
	int n;
	cin>>n;
	vector<pair<int,int>> nums(n);
	for(int i = 0; i < n; i++){
		int a,b; cin>>a>>b;
		nums[i] = mp(a,b);
	}
	sort(all(nums));
	
	int addedtime = 0;
	
	for(int i = 0; i < n-1; i++){
		if(nums[i].second + nums[i].first > nums[i+1].first){
			nums[i+1].first += (nums[i].second + nums[i].first) - nums[i+1].first;
		}
	}
	print(nums[n-1].F + nums[n-1].S);
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
