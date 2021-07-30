// Problem: Problem 3. Load Balancing
// Contest: USACO - USACO 2016 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=617
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file balancing.in  
// Output: file balancing.out  
// Attempted: 2021-07-30 12:27:39 EST
// 7/10 test cases :(

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
	ifstream cin("balancing.in");
	ofstream cout("balancing.out");
	int n,b; cin>>n>>b;
	vector<pair<int,int>> cowpos;
	int maxa = 0;
	int maxb = 0;
	int mina = INT_MAX;
	int minb = INT_MAX;
	for(int i = 0; i < n; i++){
		int a,b; cin>>a>>b;
		cowpos.pb(mp(a,b));
		maxa = max(maxa,a);
		maxb = max(maxb,b);
		mina = min(mina,a);
		minb = min(minb,b);
	}
	int ans = INT_MAX;
	
	for(int i = mina+1; i < maxa-2; i+=2){
	 	for(int j = minb+1; j < maxb-2; j += 2){
	 		// divider at i,j
	 		int bottomleft = 0;
	 		int bottomright = 0;
	 		int topleft = 0;
	 		int topright = 0;
	 		for(auto k: cowpos){
	 			if(k.F < i && k.S < j){
	 				bottomleft++;
	 			}
	 			else if(k.F > i && k.S < j){
	 				bottomright++;
	 			}
	 			else if(k.F < i && k.S > j){
	 				topleft++;
	 			}
	 			else topright++;
	 		}
	 		ans = min(ans,max({bottomleft,bottomright,topleft,topright}));
	 		
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
