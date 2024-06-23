// add me on genshin impact! 607984574
// Problem: Problem 1. Slingshot
// Attempted: 2024-06-23 15:39:59 EST

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#ifdef UwU
#include "C:\genshin_impact\keqing.cpp"
#else
#define debug(...) 0
#endif
using namespace std;
using ll = long long;
#define int long long

const int INF = 1e10;

struct segtree{
	using item = pair<int, int>;
	item merge(item a, item b){
		return {min(a.first, b.first), max(a.second, b.second)};
	}
	item single(int v){
		return {v, v};
	}
	item NEUTRAL = {INF, -INF};
	int n;
	vector<item> seg;
	segtree(int n){
		this->n = n;
		seg.resize(2 * n, NEUTRAL);
	}
	void update(int idx, int x){
		idx += n;
		seg[idx] = single(x);
		while(idx /= 2){
			seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
		}
	}
	item query(int l, int r){
		if(l > r) return NEUTRAL;
		item L = NEUTRAL, R = NEUTRAL;
		for(l += n, r += n + 1; l < r; l /= 2, r /= 2){
			if(l % 2 == 1){
				L = merge(L, seg[l++]);
			}
			if(r % 2 == 1){
				R = merge(seg[--r], R);
			}
		}
		return merge(L, R);
	}
};

template<typename T>
struct compress{
	vector<T> v;
	int n;
	compress(vector<T> _v){
		v = _v;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		n = v.size();
	}
	int operator()(T x){
		auto it = lower_bound(v.begin(), v.end(), x);
		assert(it != v.end() && *it == x);
		return it - v.begin();
	}
	int inv(int x){
		return v[x];
	}
};

signed main(){
	ifstream cin("slingshot.in");
	ofstream cout("slingshot.out");
	cin.tie(0) -> sync_with_stdio(0);
	int n, q; cin >> n >> q;
	vector<array<int, 3>> forwards, backwards;
	vector<int> relevant;
	for(int i = 0; i < n; i++){
		int x, y, t; cin >> x >> y >> t;
		if(x <= y) forwards.push_back({x, y, t});
		else backwards.push_back({y, x, t});
		relevant.push_back(x);
		relevant.push_back(y);
	}
	vector<array<int, 3>> fq, rq;
	vector<int> ans(q);
	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b;
		if(a <= b) fq.push_back({a, b, i});
		else rq.push_back({b, a, i});
		ans[i] = abs(a - b);
		relevant.push_back(a);
		relevant.push_back(b);
	}

	compress<int> comp(relevant);
	// minimize |a - x| + |b - y| + t
	for(int _ = 0; _ < 2; _++){
		vector<vector<pair<int, int>>> bridge_start(comp.n), bridge_end(comp.n);
		vector<vector<pair<int, int>>> query_start(comp.n), query_end(comp.n);
		for(int i = 0; i < forwards.size(); i++){
			bridge_start[comp(forwards[i][0])].push_back({forwards[i][1], forwards[i][2]});
			bridge_end[comp(forwards[i][1])].push_back({forwards[i][0], forwards[i][2]});
		}
		for(int i = 0; i < fq.size(); i++){
			query_start[comp(fq[i][0])].push_back({fq[i][1], fq[i][2]});
			query_end[comp(fq[i][1])].push_back({fq[i][0], fq[i][2]});
		}
		// if x <= a && y <= b
		// minimize a - x + b - y + t
		// a + b - x - y + t
		// a + b - (x + y - t)
		// maximize x + y - t
		segtree st(comp.n);
		for(int i = 0; i < comp.n; i++){
			int x = comp.inv(i);
			for(auto [y, t]: bridge_start[i]){
				st.update(comp(y), x + y - t);
			}	
			for(auto [b, i] : query_start[i]){
				pair<int, int> p = st.query(0, comp(b));
				ans[i] = min(ans[i], x + b - p.second);
			}
		}
		
		// if x <= a && b <= y
		// minimize a - x + y - b + t
		// a - b - (x - y - t)
		// maximize x - y - t
		segtree st2(comp.n);
		for(int i = 0; i < comp.n; i++){
			int x = comp.inv(i);
			for(auto [y, t]: bridge_start[i]){
				st2.update(comp(y), x - y - t);
			}	
			for(auto [b, i] : query_start[i]){
				pair<int, int> p = st2.query(comp(b), comp.n - 1);
				ans[i] = min(ans[i], x - b - p.second);
			}
		}
		
		// if a <= x && b <= y
		// x - a + y - b + t
		// -a-b + (x + y + t)
		// minimize x + y + t
		segtree st3(comp.n);
		for(int i = comp.n - 1; i >= 0; i--){
			int x = comp.inv(i);
			for(auto [y, t]: bridge_start[i]){
				st3.update(comp(y), x + y + t);
			}	
			for(auto [b, i] : query_start[i]){
				pair<int, int> p = st3.query(comp(b), comp.n - 1);
				ans[i] = min(ans[i], -x - b + p.first);
			}
		}
		
		// a <= x && y <= b
		// x - a + b - y + t
		// -a + b + (x - y + t)
		// minimize x - y + t
		segtree st4(comp.n);
		for(int i = comp.n - 1; i >= 0; i--){
			int x = comp.inv(i);
			for(auto [y, t]: bridge_start[i]){
				st4.update(comp(y), x - y + t);
			}	
			for(auto [b, i] : query_start[i]){
				pair<int, int> p = st4.query(0, comp(b));
				ans[i] = min(ans[i], -x + b + p.first);
			}
		}
		
		swap(forwards, backwards);
		swap(fq, rq);
	}
	
	for(int i: ans) cout << i << "\n";
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
