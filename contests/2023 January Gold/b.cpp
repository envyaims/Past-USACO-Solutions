#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

int N, M;
// MAX MOVES CAPPED AT 2N??
// dp[mask of lights][moves] = can turn aint lights off?

// rotates to the right
int rotate(int n, int d){
	d %= N;
	// save last d bits
	return (n >> d) | ((((1 << d) - 1) & n) << (N - d));
}

bitset<1<<20> dp[20];
int masks[20];

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int q, n; cin >> q >> n;
	
	N = n;
	M = n;
	
	int msk = 0;
	for(int i = 1; i < M; i++){
		msk = msk ^ rotate(1, i-1);
		masks[i] = msk;
	}
	dp[0][0] = 1;
	for(int moves = 1; moves < M; moves++){
		int mask = masks[moves];
		for(int light = 0; light < (1 << N); light++){
			for(int toggle = 0; toggle < N; toggle++){
				if(dp[moves-1][light ^ rotate(mask, toggle)]) dp[moves][light] = 1;
			}
		}
	}
	while(q--){
		string s, t; cin >> s >> t;
        int a = 0, b = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '1') a += 1 << (n - 1 - i);
            if(t[i] == '1') b += 1 << (n - 1 - i);
        }
		int ans = -1;
		for(int i = 0; i < M; i++){
			if(dp[i][a]){
				ans = i;
				break;
			}
			a = a ^ rotate(b, i);
		}
		if(ans == -1) cout << n << "\n";
		else cout << ans << "\n";
	}
	
}
