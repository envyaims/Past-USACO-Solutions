// add me on genshin impact! 607984574
// Problem: Problem 3. Greedy Gift Takers
// Attempted: 2024-06-22 12:06:26 EST

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#ifdef UwU
#include "C:\genshin_impact\keqing.cpp"
#else
#define debug(...) 0
#endif
using namespace std;

const int N = 1e5 + 5;
int a[N], p[N], n;

bool check(int x){
	memset(p, 0, sizeof p);
	// check any
	for(int i = 0; i < x; i++) p[a[i]]++;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += p[i];
		if(cnt > i) return true;
	}
	return false;
}

int main(){
	ifstream cin("greedy.in");
	ofstream cout("greedy.out");
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		a[i] = n - a[i] - 1;
		// cerr << a[i] << " " ;
	}
	
	int l = 0, r = n;
	while(l < r - 1){
		int mid = (l + r) / 2;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	cout << n - r << "\n";
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/