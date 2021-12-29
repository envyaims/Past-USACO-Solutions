// Author: envy <3 uwu
// Problem: Problem 1. Guard Mark
// Attempted: 2021-12-26 15:46:19 EST

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
	ifstream cin("guard.in");
	ofstream cout("guard.out");
	int n,h; cin>>n>>h;
	vt<array<int,3>> cows(n);
	FOR(i,0,n){
		cin>>cows[i][0]>>cows[i][1]>>cows[i][2];
	}
	//[height, weight, strength]
	vt<int> dp(1<<n,-1e9);
	vt<int> height(1<<n);
	
	auto in = [&](int s, int x){
		return (s&(1<<x));
	};
	
	dp[0] = 1e18;
	int ans = -1e9;
	FOR(s,1,1<<n){
		FOR(i,0,n){
			if(in(s,i)){
				height[s] += cows[i][0];
				int cw = dp[s^(1<<i)];
				if(cw >= cows[i][1]){
					ckmax(dp[s],min(cw-cows[i][1],cows[i][2]));
				}
			}
		}
		if(height[s] >= h)ckmax(ans,dp[s]);
	}
	if(ans == -1e9)cout<<"Mark is too tall";
	else cout<<ans;
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