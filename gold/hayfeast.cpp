// Author: envy <3 uwu
// Problem: Problem 3. Haybale Feast
// Attempted: 2021-12-29 09:38:46 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
#define vt vector
#define pb push_back
#define ins insert
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define F first
#define S second
#define cont continue
#define SZ(x) (int)x.size()
#define pf printf
#define retf return false
#define rett return true

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i,a,b) for (int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for (int i = (a); i > (b); --i)
#define ROFE(i,a,b) for (int i = (a); i >= (b); --i)
#define trav(a,x) for (auto& a: x)
#define rv(x) trav(i,x)cin>>i;

template<class T> using maxpq = priority_queue<T>;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};
const int MOD = 1e9+7;

void solve(){
	ifstream cin("hayfeast.in");
	ofstream cout("hayfeast.out");
	int n,m; cin>>n>>m;
	vt<pair<int,int>> v(n);
	trav(i,v){
		cin>>i.F>>i.S;
	}
	int l = 0, r = 0, ans = 1e18, flavor = 0;
	multiset<int> spice;
	while(r < n){
		while(flavor < m && r < n){
			flavor += v[r].F;
			spice.ins(v[r].S);
			r++;
			
		}
		if(flavor >= m){
			ckmin(ans,*spice.rbegin());
		}
		while(flavor >= m){
			flavor -= v[l].F;
			spice.erase(spice.find(v[l].S));
			l++;
		}
	}
	cout<<ans;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin>>t;
	while(t--){
		solve();
	}
	
}