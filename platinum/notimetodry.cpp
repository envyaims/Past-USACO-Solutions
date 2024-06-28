#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#ifdef UwU
#include "C:\genshin_impact\keqing.cpp"
#else
#define debug(...) 0
#endif
using namespace std;

struct segtree{
	using item = int;
	item merge(item a, item b){
		return a + b;
	}
	item single(int v){
		return v;
	}
	item NEUTRAL = 0;
	int n;
	vector<item> seg;
	segtree(int n){
		this->n = n;
		seg.resize(2 * n, NEUTRAL);
	}
	void update(int idx, int x){
		idx += n;
		seg[idx] += single(x);
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

// For every i, finds the largest j < i such that `compare(values[j], values[i])` is true, or -1 if no such j exists.
template<typename T, typename T_compare>
vector<int> closest_left(const vector<T> &values, T_compare &&compare) {
    int n = int(values.size());
    vector<int> closest(n);
    vector<int> stack;
 
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && !compare(values[stack.back()], values[i]))
            stack.pop_back();
 
        closest[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }
 
    return closest;
}
 

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<pair<int, int>> queries;
	for(int i = 0; i < q; i++){
		int l, r; cin >> l >> r;
		l--; r--;
		queries.push_back({l, r});
	}
	// length of segment - l, l + 1, l + 2, .. r such that a[l] == a[r] and a[l+1], a[l+2]... > a[l]
	vector<vector<pair<int, int>>> by_r(n);
	for(int i = 0; i < q; i++){
		by_r[queries[i].second].push_back({queries[i].first, i});
	}
	vector<int> c_left = closest_left(a, [&](int vj, int vi){
		return vj <= vi;
	});
	vector<int> ans(q);
	segtree st(n);
	for(int i = 0; i < n; i++){
		int left = c_left[i];
		if(left != -1 && a[left] == a[i]){
			st.update(left, 1);
		}
		for(auto [j, idx]: by_r[i]){
			ans[idx] = i - j + 1 - st.query(j, i);
		}
	}
	for(int i: ans) cout << i << "\n";
}
