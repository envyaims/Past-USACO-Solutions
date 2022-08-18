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
	cin.tie(0) -> sync_with_stdio(0);
	// go from high to low, you. If next is a higher color you dont care so you paint over it
	// if it is lower you stop your ass
	
	int n,q; cin >> n >> q;
	string s; cin >> s;
	vector<vector<int>> pref(n + 1, vector<int>(26)), suff(n + 2, vector<int>(26));
	
	vector<bool> broken(26, true); // true if a lower color intercepted previous occurrence
	for(int i = 1; i <= n; i++){
		int c = s[i - 1] - 'A';
		for(int j = c + 1; j < 26; j++){
			broken[j] = true;
		}
		for(int j = 0; j < 26; j++){
			pref[i][j] = pref[i-1][j];
		}
		if(broken[c]){
			pref[i][c]++;
			broken[c] = false;
		}
	}
	
	fill(all(broken), true);
	for(int i = n; i >= 1; i--){
		int c = s[i - 1] - 'A';
		for(int j = c + 1; j < 26; j++){
			broken[j] = true;
		}
		for(int j = 0; j < 26; j++){
			suff[i][j] = suff[i+1][j];
		}
		if(broken[c]){
			suff[i][c]++;
			broken[c] = false;
		}
	}
	
	while(q--){
		int l,r; cin >> l >> r;
		int ans = 0;
		for(int i = 0; i < 26; i++){
			ans += pref[l-1][i];
			ans += suff[r+1][i];
		}
		cout << ans << "\n";
		
	}
	
}
