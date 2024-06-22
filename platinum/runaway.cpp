#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif

struct hld_single {
 
    vector<vector<int>> adj;
    vector<int> enter, exit, head, p, d, sz;
    vector<bool> hvy;
    int n, t = 0;
 
    void _assign(int i, int v) {
        if ((p[i] = v) != -1) d[i] = d[v]+1;
        for (int j : adj[i])
            if (j != v) _assign(j, i), sz[i] += sz[j];
        int b = -1;
        for (int j : adj[i])
            if (j != v && (b == -1 || sz[j] > sz[b])) b = j;
        if (b != -1) hvy[b] = 1;
    }
 
    void _dfs(int i) {
        enter[i] = t++;
        head[i] = hvy[i] ? head[p[i]] : i;
        for (int j : adj[i])
            if (j != p[i] && hvy[j]) _dfs(j);
        for (int j : adj[i])
            if (j != p[i] && !hvy[j]) _dfs(j);
        exit[i] = t-1;
    }
 
    hld_single(vector<vector<int>> _adj = {}, int root = 0) : adj(_adj), n(_adj.size()) {
        if (_adj.size() == 0) return;
        enter.resize(n), exit.resize(n), head.resize(n);
        p.assign(n, -1), d.assign(n, 0), sz.assign(n, 1), hvy.assign(n, 0);
        _assign(root, -1), _dfs(root);
    }
 
    // returns a single interval (inclusive of both ends) which
    // represents the subtree of vertex i.
    array<int, 2> subtree(int i) const {
        return {enter[i], exit[i]};
    }
    
    int id(int x){
    	return enter[x];
    }
 
    // returns a sorted list of disjoint intervals (inclusive of both ends).
    // the list has length O(logn) and the union of the intervals represents the
    // path from vertex i to the root (inclusive of both).
    // already in id
    vector<array<int, 2>> path(int i) const {
        vector<array<int, 2>> out;
        for (; i != -1; i = p[head[i]])
            out.push_back({enter[head[i]], enter[i]});
        reverse(out.begin(), out.end());
        return out;
    }
 
    // returns a sorted list of disjoint intervals (inclusive of both ends).
    // the list has length O(logn) and the union of the intervals represents the
    // path from vertex i to vertex j (inclusive of both).
    // already in id
    vector<array<int, 2>> path(int i, int j) const {
        vector<array<int, 2>> tmp, out;
        for (; head[i] != head[j]; j = p[head[j]]) {
            if (d[head[i]] > d[head[j]]) swap(i, j);
            tmp.push_back({enter[head[j]], enter[j]});
        }
        if (d[i] > d[j]) swap(i, j);
        tmp.push_back({enter[i], enter[j]});
        sort(tmp.begin(), tmp.end());
        for (auto [l, r] : tmp) {
            if (!out.empty() && out.back()[1] == l-1)
                l = out.back()[0], out.pop_back();
            out.push_back({l, r});
        }
        return out;
    }
};

int main(){
	// ifstream cin("runaway.in");
	// ofstream cout("runaway.out");
	cin.tie(0) -> sync_with_stdio(0);
	int N; ll L; cin >> N >> L;
	vector<vector<int>> g(N);
	vector<ll> len(N);
	for(int i = 1; i < N; i++){
		int p; ll l; cin >> p >> l;
		--p;
		g[p].push_back(i);
		g[i].push_back(p);
		len[i] = l;
	}
	hld_single hld(g);
	vector<ll> p_len(N);
	for(int i = 0; i < N; i++) p_len[hld.id(i)] = len[i];
	for(int i = 1; i < N; i++) p_len[i] += p_len[i - 1];
	vector<ll> p(N);
	for(int i = 0; i < N; i++){
		auto path = hld.path(i); // might need to reverse
		ll su = 0;
		reverse(path.begin(), path.end());
		debug(path);
		for(auto [lb, rb] : path){
			ll len_sum = p_len[rb] - (lb == 0 ? 0 : p_len[lb - 1]);
			debug(i, len_sum);
			if(su + len_sum <= L){
				su += len_sum;
				if(lb > 0) p[lb - 1]--;
				p[rb]++;
				continue;
			}
			int l = lb, r = rb + 1;
			while(l < r - 1){
				int mid = (l + r) / 2;
				if(su + p_len[rb] - p_len[mid] > L){
					l = mid;
				}
				else{
					r = mid;
				}
			}
			debug(i, l);
			p[l]--;
			p[rb]++;
			break;
		}
	}
	
	for(int i = N - 2; i >= 0; i--) p[i] += p[i + 1];
	for(int i = 0; i < N; i++) cout << max(1LL, p[hld.id(i)]) << "\n"; 
}