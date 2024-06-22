// Author: envy <3 uwu
// Problem: Problem 2. Problem Setting
// Attempted: 2023-03-19 09:20:26 EST

#pragma GCC optimize("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;

ll modpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

struct mint{

	ll v;
	mint() {v = 0;}
	mint(ll V): v(ll(V % MOD)) {v += (v < 0) * MOD;}
	mint& operator+=(mint other){
		v += other.v;
		if(v >= MOD) v -= MOD;
		return *this;
	}
	mint& operator-=(mint other){
		v -= other.v;
		if(v < 0) v += MOD;
		return *this;
	}
	mint& operator*=(mint other){
		v = (v * other.v) % MOD;
		return *this;
	}
	mint& operator/=(mint other){
		v = (v * modpow(other.v, MOD-2)) % MOD;
		return *this;
	}
	friend mint operator+(mint a, mint b) { return a += b; }
	friend mint operator-(mint a, mint b) { return a -= b; }
	friend mint operator*(mint a, mint b) { return a *= b; }
	friend mint operator/(mint a, mint b) { return a /= b; }
	friend ostream& operator<<(ostream& o, mint cur) { return o << cur.v; }
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m; cin >> n >> m;
	vector<string> s(m);
	for(string& i: s) cin >> i;
	
	vector<mint> fact(n+1);
	fact[0] = fact[1] = 1;
	for(int i = 2; i <= n; i++) fact[i] = fact[i-1] * i;
	
	auto nPr = [&](int x) -> mint{
		mint res = 0;
		for(int i = 0; i <= x; i++){
			res += fact[x] / fact[x - i];
		}
		return res - 1;
	};
	
	vector<int> cnt(1 << m);
	for(int i = 0; i < n; i++){
		int msk = 0;
		for(int j = 0; j < m; j++){
			if(s[j][i] == 'H'){
				msk |= 1 << j;
			}
		}
		cnt[msk]++;
	}
	
	vector<mint> dp(1 << m);
	for(int i = 0; i < (1 << m); i++){
		mint sum = 1;
		for(int j = (i - 1) & i; true; j = (j - 1) & i){
			sum += dp[j];
			if(j == 0) break;
		}
		dp[i] = sum * nPr(cnt[i]);
	}
	mint ans = 0;
	for(int i = 0; i < (1 << m); i++) ans += dp[i];
	cout << ans << endl;

}