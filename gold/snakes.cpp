// uwuenvy <3

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
	ifstream cin("snakes.in");
	ofstream cout("snakes.out");
	cin.tie(0) -> sync_with_stdio(0);
	int n,k; cin >> n >> k;
	
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, 1e9)));
	for(int i = 0; i <= k; i++){
		for(int j = 1; j <= n; j++){
			dp[0][i][j] = 0;
		}
	}
	// dp[first i snakes][changed j times][net size] = minimize total space wasted
	
	for(int i = 1; i <= n; i++){
		vector<int> minloss(k, 1e9);
		for(int net = 1; net <= n; net++){
			for(int j = 0; j < k; j++){
				minloss[j] = min(minloss[j], dp[i-1][j][net]);
			}
		}
		
		for(int net = 1; net <= n; net++){
			if(a[net] < a[i]) continue;
			// stay same net
			for(int j = 0; j <= k; j++){
				dp[i][j][net] = min(dp[i][j][net], dp[i-1][j][net] + a[net] - a[i]);
			}
			
			// change net
			for(int j = 1; j <= k; j++){
				dp[i][j][net] = min(dp[i][j][net], minloss[j-1] + a[net] - a[i]);
			}
		}
	}
	int ans = 1e9;
	for(int net = 1; net <= n; net++){
		for(int j = 0; j <= k; j++){
			ans = min(ans, dp[n][j][net]);
		}
	}
	cout << ans << "\n";
}
