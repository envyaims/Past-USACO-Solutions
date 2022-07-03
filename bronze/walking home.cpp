#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "../template/debug.cpp"
#endif

using namespace std;
using ll = int_fast64_t;

void solve(){
	int N, K; cin >> N >> K;
	char grid[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> grid[i][j];
		}
	}
	ll dp[N][N][K + 1][2];
	// dp[row][col][number of times direction changed][0 = down, 1 = right]
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k <= K; k++){
				for(int l = 0; l < 2; l++){
					dp[i][j][k][l] = 0;
				}
			}
		}
	}
	dp[0][1][0][1] = 1;
	dp[1][0][0][0] = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(grid[i][j] == 'H') continue;
			for(int k = 0; k <= K; k++){
				// walk the same direction
				if(i < N - 1){
					// keep walking down
					dp[i+1][j][k][0] += dp[i][j][k][0];
				}
				if(j < N - 1){
					// keep walking to the right
					dp[i][j+1][k][1] += dp[i][j][k][1];
				}
				
				if(k < K){
					// change directions
					if(i < N - 1){
						// was walking to the right, but now change and walk down
						dp[i+1][j][k+1][0] += dp[i][j][k][1];
					}
					if(j < N - 1){
						// was walking to the down, but now change and walk right
						dp[i][j+1][k+1][1] += dp[i][j][k][0];
					}
				}
			}
		}
	}
	
	ll ans = 0;
	for(int k = 0; k <= K; k++){
		for(int i = 0; i < 2; i++){
			ans += dp[N-1][N-1][k][i];
		}
	}
	cout << ans << endl;
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
