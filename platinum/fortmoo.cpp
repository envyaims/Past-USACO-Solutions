// add me on genshin impact! 607984574
// Problem: Problem 1. Fort Moo
// Attempted: 2024-06-18 17:18:50 EST

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
const int INF = 1e9;
const ll INFLL = 1e18;
 
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define sz(x) (int)x.size()
#define make_unique(v) sort(all(v)); v.erase(unique(all(v)), v.end())

template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
	ifstream cin("fortmoo.in");
	ofstream cout("fortmoo.out");
	int n, m; cin >> n >> m;
	vector<string> g(n); cin >> g;
	vt<2,int> rp(n, m), cp(n, m);
	FOR(i,0,n) FOR(j,0,m) cp[i][j] = (j ? cp[i][j-1] : 0) + (g[i][j] == 'X');
	FOR(j,0,m) FOR(i,0,n) rp[i][j] = (i ? rp[i-1][j] : 0) + (g[i][j] == 'X');
	auto c_query = [&](int r, int c1, int c2){
		return cp[r][c2] - (c1 == 0 ? 0 : cp[r][c1 - 1]);
	};
	auto r_query = [&](int c, int r1, int r2){
		return rp[r2][c] - (r1 == 0 ? 0 : rp[r1 - 1][c]);
	};
	int ans = 0;
	FOR(r1,0,n){
		FOR(r2,r1,n){
			vector<int> good_c;
			FOR(c,0,m){
				if(r_query(c, r1, r2) == 0){
					good_c.pb(c);
				}
			}
			FOR(i,0,sz(good_c)){
				int c1 = good_c[i];
				int l = i, r = sz(good_c);
				while(l < r - 1){
					int mid = (l + r) / 2;
					int c2 = good_c[mid];
					if(c_query(r1, c1, c2) == 0 && c_query(r2, c1, c2) == 0){
						l = mid;
					}
					else{
						r = mid;
					}
				}
				int c2 = good_c[l];
				// debug(r1, r2, c1, c2);
				ckmax(ans, (r2 - r1 + 1) * (c2 - c1 + 1));
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/