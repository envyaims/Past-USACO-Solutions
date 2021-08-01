// Problem: Problem 3. Breed Counting
// Contest: USACO - USACO 2015 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=572
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file bcount.in  
// Output: file bcount.out  
// Attempted: 2021-07-31 20:37:03 EST
// AC

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
	ifstream cin("bcount.in");
	ofstream cout("bcount.out");
	int n,q;
	cin>>n>>q;
	vector<vector<int>> nums(n+1, vector<int>(3,0));
	
	for(int i = 1; i <= n; i++){
		int a; cin>>a;
		nums[i][0] = nums[i-1][0];
		nums[i][1] = nums[i-1][1];
		nums[i][2] = nums[i-1][2];
		nums[i][a-1]++;
	}
	
	while(q--){
		int l,r; cin>>l>>r;
		cout<< nums[r][0] - nums[l-1][0]<<" ";
		cout<< nums[r][1] - nums[l-1][1]<<" ";
		cout<< nums[r][2] - nums[l-1][2]<<"\n";
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
