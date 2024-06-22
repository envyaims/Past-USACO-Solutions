// add me on genshin impact! 607984574
// Problem: Problem 1. Modern Art
// Attempted: 2024-06-22 09:47:14 EST

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#ifdef UwU
#include "C:\genshin_impact\keqing.cpp"
#else
#define debug(...) 0
#endif
using namespace std;
using ll = long long;

const int N = 1005, C = 1005 * 1005;

#define left shauobdsd
#define right oujbsadoiabf

int g[N][N], p[N][N];
int top[C], left[C], right[C], down[C], bad[C];

void take_min(int& a, int b){
	if(a == 0) a = b;
	a = min(a, b);
}

void take_max(int& a, int b){
	a = max(a, b);
}



int main(){
	// ifstream cin("art.in");
	// ofstream cout("art.out");
	cin.tie(0) -> sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> g[i][j];
			take_min(top[g[i][j]], i);
			take_max(down[g[i][j]], i);
			take_min(left[g[i][j]], j);
			take_max(right[g[i][j]], j);
		}
	}
	for(int i = 1; i <= n * n; i++){
		if(!top[i]) continue;
		p[top[i]][left[i]]++;
		p[top[i]][right[i]+1]--;
		p[down[i]+1][left[i]]--;
		p[down[i]+1][right[i]+1]++;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
			if(p[i][j] > 1) bad[g[i][j]] = 1;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n * n; i++){
		if(!bad[i]) ans++;
	}
	
	int cnt_z = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cnt_z += g[i][j] == 0;
		}
	}
	
	if(cnt_z == n * n){
		cout << 0 << "\n";
		return 0;
	}
	
	cout << ans << endl;
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/