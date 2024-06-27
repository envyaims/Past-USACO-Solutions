// add me on genshin impact! 607984574
// Problem: Problem 1. Cave Paintings
// Attempted: 2024-06-26 20:33:42 EST

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#ifdef UwU
#include "C:\genshin_impact\keqing.cpp"
#else
#define debug(...) 0
#endif
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

template<ll M>
struct modint {
 
    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }
 
    ll v; modint(ll n = 0) : v(n%M) { v += (M&(0-(v<0))); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }
 
    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }
 
    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }
 
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};
 
using mint = modint<int(MOD)>;

struct DSU{
	vector<int> p;
	vector<mint> dp;
	DSU(int n){
		p.resize(n);
		iota(p.begin(),p.end(),0);
		dp.resize(n, 1);
	}
	int get(int x){
		if(p[x] != x){
			p[x] = get(p[x]);
		}
		return p[x];
	}
	void unite(int a, int b){
		a = get(a); b = get(b);
		if(a != b){
			p[b] = a;
			dp[a] *= dp[b];
		}
	}
};

int n, m;

ll h(int i, int j){
	return i * m + j;
}

int main(){
	ifstream cin("cave.in");
	ofstream cout("cave.out");
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	vector<vector<char>> g(n, vector<char>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> g[i][j];
		}
	}
	DSU dsu(n * m);
	for(int i = n - 2; i >= 0; i--){
		for(int j = 0; j < m; j++){
			if(g[i][j] == '.'){
				if(g[i+1][j] == '.'){
					dsu.unite(h(i, j), h(i+1, j));
				}
				if(j && g[i][j-1] == '.'){
					dsu.unite(h(i, j), h(i, j-1));
				}
			}
		}
		for(int j = 0; j < m; j++){
			if(dsu.get(h(i, j)) == h(i, j)){
				dsu.dp[h(i, j)]++;
			}
		}
	}
	mint ans = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] == '.' && dsu.get(h(i, j)) == h(i, j)){
				ans *= dsu.dp[h(i, j)];
			}
		}
	}
	cout << ans << "\n";
	
}
