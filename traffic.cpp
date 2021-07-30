// Problem: Problem 3. Measuring Traffic
// Contest: USACO - USACO 2019 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=917
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file traffic.in  
// Output: file traffic.out  
// Attempted: 2021-07-30 08:10:21 EST
// ALL TEST CASES PASSED (except one lol)

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
	ifstream cin("traffic.in");
	ofstream cout("traffic.out");
	int n;
	cin>>n;
	pair<int,int> end = mp(-1000000,1000000);
	vector<pair<string,pair<int,int>>> infos;
	for(int i = 0; i < n; i++){
		string s;
		int a,b;
		cin>>s>>a>>b;
		
		int maxf,mins;
		
		if(s == "none"){
			maxf = max(end.F,a);
			mins = min(end.S,b);
			end = mp(maxf,mins);
		}
		else if(s == "on"){
			maxf = end.F + a;
			mins = end.S + b;
			end = mp(maxf,mins);
		}
		else if(s == "off"){
			maxf = end.F - b;
			mins = end.S - a;
			end = mp(maxf,mins);
		}
		
		infos.pb(mp(s,mp(a,b)));
	}
	
	pair<int,int> start = mp(-1000000,1000000);
	
	for(int i = n-1; i >= 0; i--){
		string s = infos[i].F;
		int a = infos[i].S.F;
		int b = infos[i].S.S;
		int maxf,mins;
		
		if(s == "none"){
			maxf = max(start.F,a);
			mins = min(start.S,b);
			start = mp(maxf,mins);
		}
		else if(s == "off"){
			maxf = start.F + a;
			mins = start.S + b;
			start = mp(maxf,mins);
		}
		else if(s == "on"){
			maxf = start.F - b;
			mins = start.S - a;
			start = mp(maxf,mins);
		}
	}
	
	cout<<start.F <<" "<<start.S<<endl;
	cout<<end.F<<" "<<end.S<<endl;
		 
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
