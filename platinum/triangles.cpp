// Author: envy <3 uwu
// Problem: Problem 1. Lots of Triangles
// Attempted: 2022-06-09 17:20:36 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define pq priority_queue
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define read(x) trav(i,x)cin >> i
 
template<class T> using minpq = pq<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
	
// cross < 0 = c is on the left side of a -> b
ll cross(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
	b.F -= a.F; b.S -= a.S; c.F -= a.F; c.S -= a.S;
	return b.F * c.S - b.S * c.F;
}

// determine if d is in the triangle
int triangle(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c, pair<ll,ll> d){
	return cross(a,b,d) > 0 && cross(b,c,d) > 0 && cross(c,a,d) > 0;
}

const int N = 300;

bitset<N> in[N][N];

void solve() {
	ifstream cin("triangles.in");
	ofstream cout("triangles.out");
	
	int n; cin >> n;
	vector<pair<ll,ll>> a(n);
	FOR(i,0,n)cin>>a[i].F>>a[i].S;
	
	FOR(i,0,n)FOR(j,0,n)if(i != j)FOR(k,0,n){
		if(cross(a[i],a[j],a[k]) > 0)in[i][j][k] = 1;
	}
	
	vector<int> ans(n-2);
	FOR(i,0,n)FOR(j,i+1,n)FOR(k,j+1,n){
		vector<int> cur = {i,j,k};
		if(cross(a[cur[0]], a[cur[1]], a[cur[2]]) < 0){
			swap(cur[1], cur[2]);
		}
		auto cnt = in[cur[0]][cur[1]] & in[cur[1]][cur[2]] & in[cur[2]][cur[0]];
		ans[cnt.count()]++;
	}
	trav(i,ans){
		cout << i << endl;
	}
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}