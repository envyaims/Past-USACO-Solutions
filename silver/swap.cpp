// author: envy <3

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;
using ll = long long;

vector<int> assign(vector<int> a){
	vector<int> moveto(a.size());
	for(int i = 0; i < a.size(); i++){
		moveto[a[i]] = i;
	}
	return moveto;
}

vector<int> change(vector<int> a, vector<int> x){
	vector<int> cur(a.size());
	for(int i = 0; i < a.size(); i++){
		cur[x[i]] = a[i];
	}
	return cur;
}

vector<int> expo(vector<int> a, vector<int> x, int b){
	while(b > 0){
		debug(b, x);
		if(b % 2 == 1){
			a = change(a, x);
		}
		vector<int> c = assign(x);
		x = change(x, c);
		b /= 2;
	}
	return a;
}

void solve(){
	ifstream cin("swap.in");
	ofstream cout("swap.out");
	int n,m,k; cin >> n >> m >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
	while(m--){
		int l,r; cin >> l >> r;
		reverse(a.begin() + l, a.begin() + r + 1);
	}
	
	
	vector<int> cur(n + 1);
	for(int i = 1; i <= n; i++){
		cur[i] = i;
	}
	
	vector<int> res = expo(cur, assign(a), k);
	for(int i = 1; i <= n; i++){
		cout << res[i] << "\n";
	}
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1; 
	// cin >> t;
	while(t--){
		solve();
	}
}
