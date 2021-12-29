// Author: envy <3 uwu
// Problem: Problem 2. Radio Contact
// Attempted: 2021-12-26 09:21:49 EST

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

const int MOD = 1e9+7;

void solve(){
	ifstream cin("radio.in");
	ofstream cout("radio.out");
	int n,m; cin>>n>>m;
	vt<pair<int,int>> j(n+1), b(m+1);
	cin>>j[0].F>>j[0].S;
	cin>>b[0].F>>b[0].S;
	string jp, bp; cin>>jp>>bp;
	
	map<char,int> dir;
	dir['N'] = 0;
	dir['S'] = 1;
	dir['W'] = 2;
	dir['E'] = 3;
	
	const int dy[4] = {1,-1,0,0};
	const int dx[4] = {0,0,-1,1};
	
	
	FORE(i,1,n){
		j[i] = {j[i-1].F + dx[dir[jp[i-1]]], j[i-1].S + dy[dir[jp[i-1]]]};
	}
	FORE(i,1,m){
		b[i] = {b[i-1].F + dx[dir[bp[i-1]]], b[i-1].S + dy[dir[bp[i-1]]]};
	}
	
	auto dist = [&](pair<int,int> A, pair<int,int> B){
		int x = A.F - B.F;
		int y = A.S - B.S;
		return x*x+y*y;
	};
	
	vt<vt<int>> dp(n+1,vt<int>(m+1,1e18));
	dp[0][0] = 0;
	FOR(x,0,n){
		FOR(y,0,m){
			ckmin(dp[x+1][y],dp[x][y] + dist(j[x+1],b[y]));
			ckmin(dp[x][y+1],dp[x][y] + dist(j[x],b[y+1]));
			ckmin(dp[x+1][y+1],dp[x][y] + dist(j[x+1],b[y+1]));
		}
	}
	cout<<dp[n][m];
	
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