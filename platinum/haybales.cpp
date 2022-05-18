#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
using ll = long long;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
const int MOD = 1e9 + 7;
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

template<int N, typename T = int>
struct lazyseg {
	
	constexpr static T max_T = numeric_limits<T>::max();
	constexpr static T min_T = numeric_limits<T>::min();
	constexpr static int H = int(ceil(log2(N))), _N = 1<<H;
	
	struct node { T s, l, r; } t[2*_N];
	node merge(node x, node y) {
		return {x.s+y.s, std::min(x.l, y.l), std::max(x.r, y.r)};
	}
	
	T u[2*_N]; bool f[2*_N]; int a[2*_N], b[2*_N];
	lazyseg() {
		fill(t, t+2*_N, node({0, 0, 0}));
		fill(f, f+2*_N, 0), fill(u, u+2*_N, 0);
		iota(a+_N, a+2*_N, 0), iota(b+_N, b+2*_N, 0);
		for (int i = _N-1; i > 0; i--)
			a[i] = a[2*i], b[i] = b[2*i+1];
	}
	
	void apply(int i, T x, bool ins) {
		if (ins) u[i] = x, f[i] = 1;
		else u[i] += x;
	}
	
	void push(int i) {
		if (!f[i] && !u[i]) return;
		if (f[i]) t[i] = {0, 0, 0};
		t[i].s += u[i]*(b[i]-a[i]+1), t[i].l += u[i], t[i].r += u[i];
		if (i < _N) apply(2*i, u[i], f[i]), apply(2*i+1, u[i], f[i]);
		u[i] = f[i] = 0;
	}
	
	void _upd(int l, int r, T x, bool ins, int i = 1) {
		if (l <= a[i] && r >= b[i]) apply(i, x, ins);
		push(i);
		if (l > b[i] || r < a[i] || (l <= a[i] && r >= b[i])) return;
		_upd(l, r, x, ins, 2*i), _upd(l, r, x, ins, 2*i+1);
		t[i] = merge(t[2*i], t[2*i+1]);
	}
	
	node _qry(int l, int r, int i = 1) {
		push(i);
		if (l <= a[i] && r >= b[i]) return t[i];
		if (l > b[i] || r < a[i]) return {0, max_T, min_T};
		return merge(_qry(l, r, 2*i), _qry(l, r, 2*i+1));
	}
	
	T get(int i) {
		for (int x = H; x >= 0; x--) push((_N+i)>>x);
		return t[_N+i].s;
	}
	
	void set(int l, int r, T x) { _upd(l, r, x, 1); }
	void add(int l, int r, T x) { _upd(l, r, x, 0); }
	void set(int i, T x) { set(i, i, x); }
	void add(int i, T x) { add(i, i, x); }
	T sum(int l, int r) { return _qry(l, r).s; }
	T min(int l, int r) { return _qry(l, r).l; }
	T max(int l, int r) { return _qry(l, r).r; }
};

const int N = 2e5 + 5;
lazyseg<N,ll> seg;

void solve() {
	ifstream cin("haybales.in");
	ofstream cout("haybales.out");
	int n,q; cin >> n >> q;
	for(int i = 1; i <= n; i++){
		int x; cin >>x;
		seg.set(i,x);
	}
	while(q--){
		char t; int l, r; cin >> t >> l >> r;
		if(t == 'M'){
			cout << seg.min(l,r) << endl;
		}
		else if(t == 'P'){
			int x; cin >> x;
			seg.add(l,r,x);
		}
		else if(t == 'S'){
			cout << seg.sum(l,r) << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
