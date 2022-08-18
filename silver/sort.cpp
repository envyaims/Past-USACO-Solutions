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

void sim(vector<int> a){
	bool sorted = false;
	while(!sorted){
		sorted = true;
		debug(a);
		for(int i = 0; i < sz(a) - 1; i++){
			if(a[i+1] < a[i]){
				swap(a[i], a[i+1]);
				sorted = false;
			}
		}
	}
}

int main(){
	ifstream cin("sort.in");
	ofstream cout("sort.out");
	cin.tie(0) -> sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	for(int& i: a) cin >> i;
	vector<pair<int,int>> p;
	for(int i = 0; i < n; i++) p.emplace_back(a[i], i);
	sort(all(p));
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, p[i].second - i);
	}
	cout << ans + 1 << "\n";
}
