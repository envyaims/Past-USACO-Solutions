// Problem: Problem 2. Cities and States
// Contest: USACO - USACO 2016 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=667
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file citystate.in  
// Output: file citystate.out  
// Attempted: 2021-07-30 19:48:15 EST
// all test cases passsed lol

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
	ifstream cin("citystate.in");
	ofstream cout("citystate.out");
	int n;
	cin>>n;
	
	map<pair<string,string>,int> cities;
	int ans = 0;
	for(int i = 0; i < n; i++){
		string a,b; cin>>a>>b;
		string title = a.substr(0,2);
		if(title != b){
			ans += cities[mp(b,title)];
			cities[mp(title,b)]++;
		}
	}
	// for(int i = 0; i < n-1; i++){
		// for(int j = i+1; j < n; j++){
			// if(cities[i].F == cities[j].S && cities[i].S == cities[j].F)ans++;
		// }
	// }
	print(ans);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
