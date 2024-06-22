// keqing best girl <3
// Problem: Problem 2. Team Building
// Attempted: 2023-12-23 19:20:49 EST

#include <bits/stdc++.h>

#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif

using namespace std;
const int MOD = 1e9 + 9;
using ll = long long;
#define all(x) x.begin(), x.end()

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
	friend mint operator+(mint a, mint b) { return a += b; }
	friend mint operator-(mint a, mint b) { return a -= b; }
};

struct twodps{
	vector<vector<mint>> pref;
	
	// MAKE SURE ONE INDEXED
	twodps(vector<vector<mint>> g){
		int n = g.size(), m = g[0].size();
		pref.resize(n, vector<mint>(m));
		for(int i = 1; i < n; i++){
			for(int j = 1; j < m; j++){
				pref[i][j] = g[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
			}
		}
	}
	
	// returns sum in the subrectangle, inclusive
	mint operator()(int r1, int c1, int r2, int c2){
		if(r2 < r1 || c2 < c1) return 0;
		return pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
	}
};

void solve(){
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	
	int n, m, k; cin >> n >> m >> k;
	vector<ll> a(n + 1), b(m + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
	}
	sort(all(a));
	sort(all(b));
	
	vector<vector<vector<mint>>> dp(k + 1, vector<vector<mint>>(n + 1, vector<mint>(m + 1)));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i] > b[j]){
				dp[1][i][j] = 1;
			}
		}
	}
	for(int rounds = 2; rounds <= k; rounds++){
		// number of ways such that i < cur_i and j < cur_j
		twodps pref(dp[rounds - 1]);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i] > b[j]){
					dp[rounds][i][j] = pref(1, 1, i - 1, j - 1);
				}
			}
		}
	}
	
	mint ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans += dp[k][i][j];
		}
	}
	cout << ans.v << "\n";
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int T = 1;
	// cin >> T;
	while(T--) solve();
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/