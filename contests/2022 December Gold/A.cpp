// only 15/20 tcs :(

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 205, mx = 2005;
ll dp[N][N][N];
ll dp2[mx][mx];

struct item{
	ll p, c, x;
};

void ckmax(ll& a, ll b){
	a = max(a, b);
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	ll n, a, b; cin >> n >> a >> b;
	vector<item> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].p >> v[i].c >> v[i].x;
	}
	
	auto solve_one = [&](){
		memset(dp2, -0x3f, sizeof dp2);
		dp2[0][a] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= a; j++){
				ckmax(dp2[i][j], dp2[i-1][j]);
				if(j <= a - v[i-1].c) ckmax(dp2[i][j], dp2[i-1][j + v[i-1].c] + v[i-1].p);
			}
		}
		ll ans = 0;
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= a; j++){
				ckmax(ans, dp2[i][j]);
			}
		}
		cout << ans << "\n";
	};
	
	if(b == 0){
		solve_one();
		return 0;
	}
	
	memset(dp, -0x3f, sizeof dp);
	dp[0][a][b] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= a; j++){
			for(int k = 0; k <= b; k++) dp[i][j][k] = dp[i-1][j][k];
			for(int use_cones = 0; use_cones <= b; use_cones++){
				int new_price = v[i-1].c - use_cones/v[i-1].x;
				if(new_price < 0 || j + new_price > a) continue;
				for(int cones = 0; cones <= b - use_cones; cones++){
					ckmax(dp[i][j][cones], dp[i-1][j + new_price][cones + use_cones] + v[i-1].p);
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= a; j++){
			for(int k = 0; k <= b; k++){
				ckmax(ans, dp[i][j][k]);
			}
		}
	}
	cout << ans << endl;
}
