// Problem: Problem 2. Subsequences Summing to Sevens
// Contest: USACO - USACO 2016 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=595
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file div7.in  
// Output: file div7.out  
// Attempted: 2021-07-31 20:51:21 EST

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
	ifstream cin("div7.in");
	ofstream cout("div7.out");
	int n;
	cin>>n;
	vector<int> first(7,-1);
	int ans = 0;
	int remainder = 0;
	for(int i = 1; i <= n; i++){
		int a; cin>>a;
		int mod = (a + remainder) % 7;
		remainder = mod;
		if(first[mod] == -1){
			first[mod] = i;
		}
		else{
			ans = max(ans,i - first[mod]);
		}
	}
	
	
	print(ans);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
