// cum is the only solution

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "../template/debug.cpp"
#endif

using namespace std;
using ll = int_fast64_t;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int main(){
	ifstream cin("diamond.in");
	ofstream cout("diamond.out");
	cin.tie(0) -> sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int& i: a) cin >> i;
	sort(all(a));
	
	vector<int> cantake(n);
	for(int i = 0; i < n; i++){
		auto it = upper_bound(all(a), a[i] + k);
		cantake[i] = (it - a.begin()) - i;
	}
	vector<int> maxtake(n+1);
	for(int i = n - 1; i >= 0; i--){
		maxtake[i] = max(maxtake[i + 1], cantake[i]);
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		int up = upper_bound(all(a), a[i] + k) - a.begin();
		ans = max(ans, up - i + maxtake[up]);
	}
	cout << ans << endl;
	
}
