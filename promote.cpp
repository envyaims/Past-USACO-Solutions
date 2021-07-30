// Problem: Problem 1. Promotion Counting
// Contest: USACO - USACO 2016 January Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=591
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file promote.in  
// Output: file promote.out  
// Attempted: 2021-07-30 14:25:24 EST

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
	ifstream cin("promote.in");
	ofstream cout("promote.out");
	int a1,a2,b1,b2,c1,c2,d1,d2;
	cin>>a1>>a2>>b1>>b2>>c1>>c2>>d1>>d2;
	
	int ctod = d2-d1;
	int btoc = c2-c1 + d2-d1;
	int atob = b2-b1 + c2-c1 + d2-d1;
	
	print(atob);
	print(btoc);
	print(ctod);
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
