// Author: envy <3 uwu
// Problem: Problem 1. Sleepy Cow Herding
// Attempted: 2022-10-28 22:45:08 EST

#include <bits/stdc++.h>

#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

int main(){
	ifstream cin("herding.in");
	ofstream cout("herding.out");
	cin.tie(0) -> sync_with_stdio(0);
	int T = 1;
	// cin >> T;
	for(int _ = 0; _ < T; _++){
		int n; cin >> n;
		vector<int> a(n);
		for(int& i: a) cin >> i;
		sort(a.begin(), a.end());
		
		auto next_invalid = [&](int x, int add) -> int{
			return lower_bound(a.begin(), a.end(), x + add) - a.begin();
		};
		
		int min_ans = 3e9;
		for(int i = 0; i < n; i++){
			min_ans = min(min_ans, i + (n - next_invalid(a[i], n)));
		}
		
		// edge case bruv
		if(next_invalid(a[0], n) == n - 1 && a[n-1] - a[n-2] > 2) min_ans = 2;
		if(next_invalid(a[1], n-1) == n && a[1] - a[0] > 2) min_ans = 2;
		
		int gaps = 0;
		for(int i = 0; i < n - 1; i++){
			gaps += a[i+1] - a[i] - 1;
		}
		int min_skip = min(a[1] - a[0] - 1, a[n-1] - a[n-2] - 1);
		int max_ans = gaps - min_skip;
		cout << min_ans << endl << max_ans << endl;
	}
}
