// Author: envy <3 uwu
// Problem: Problem 1. Bovine Genomics
// Attempted: 2021-12-31 21:18:00 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
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
#define read(x) trav(i,x)cin>>i;

template<class T> using maxpq = priority_queue<T>;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};
const int MOD = 1e9+7;

void solve(){
	ifstream cin("cownomics.in");
	ofstream cout("cownomics.out");
	int n,m; cin>>n>>m;
	vt<string> a(n), b(n);
	read(a); read(b);
	
	vt<int> hashbrown(m);
	FOR(i,0,m){
		hashbrown[i] = rand() % 1000000000 + 7;
	}	
	
	
	auto check = [&](int x){
		vt<int> ahash(n);
		map<int,bool> hashes;
		FOR(i,0,x){
			FOR(j,0,n){
				ahash[j] += a[j][i] * hashbrown[i];
			}
		}
		
		FOR(i,0,n){
			hashes[ahash[i]] = true;
		}
		
		FOR(i,x,m){
			FOR(j,0,n){
				ahash[j] -= a[j][i-x] * hashbrown[i-x];
				ahash[j] += a[j][i] * hashbrown[i];
				hashes[ahash[j]] = true;
			}
		}
		vt<int> bhash(n);
		FOR(i,0,x){
			FOR(j,0,n){
				bhash[j] += b[j][i] * hashbrown[i];
			}
		}
		
		int cnt = 0;		
		FOR(i,0,n){
			if(!hashes[bhash[i]])cnt++;
		}
		if(cnt == n)return true;
		
		FOR(i,x,m){
			cnt = 0;
			FOR(j,0,n){
				bhash[j] -= b[j][i-x] * hashbrown[i-x];
				bhash[j] += b[j][i] * hashbrown[i];
				if(!hashes[bhash[j]])cnt++;
			}
			if(cnt == n)return true;
		}
		
		return false;
		
	};
	
	//debug(check(2));
	
	int l = 0, r = m;
	while(l < r-1){
		int mid = (l+r)/2;
		if(check(mid)){
			r = mid;
		}
		else l = mid;
	}
	cout<<r;
	
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
