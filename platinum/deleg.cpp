#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> g[N];
int to_be_merged[N];

// check if elements can be paired with sum >= k
bool check(vector<int> &v, int remove, int k) {
	int l = 0;
	int r = v.size() - 1;
	while (l < r) {
		if (l == remove) { l++; }
		if (r == remove) { r--; }
		if (v[l++] + v[r--] < k) { return false; }
	}
	return true;
}


bool dfs(int node, int p, int k) {
	vector<int> v;  // all leftover path lengths from children
	for (int i : g[node]) {
		if (i == p) continue;
		if (!dfs(i, node, k)) return false;
		v.push_back(to_be_merged[i] + 1);
	}
	
	// root edge case
	if(node == 0){
		// if it is the root, all paths must be evenly paired
		// there must be an even number of paths initially
		if (v.size() % 2 == 1) {
			v.push_back(0);
		}
		// return if possible if we do not remove any elements
		return check(v, -1, k);
	}
	
	if (v.size() % 2 == 0) {
		// append dummy 0 (returned if perfectly paired)
		v.push_back(0);
	}
	sort(v.begin(), v.end());

	// binary search over the index we can remove
	int l = -1;
	int r = v.size();
	while (l < r - 1) {
		int mid = l + (r - l) / 2;
		// if we remove index mid, can we pair the rest?
		if (check(v, mid, k)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	
	// we cannot pair all paths even if we removed an index
	if (l == -1) { return false; }

	to_be_merged[node] = v[l];
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	
	int l = 0;
	int r = n + 1;
	while (l < r - 1) {
		int mid = l + (r - l) / 2;
		fill(to_be_merged, to_be_merged + n, 0);
		if (dfs(0, 0, mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}

	cout << l << endl;
}