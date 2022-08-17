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
	ifstream cin("dishes.in");
	ofstream cout("dishes.out");
	
	cin.tie(0) -> sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	for(int& i: a) cin >> i;
	
	auto check = [&](int x){
		deque<int> stk;
		for(int i = 0; i < x; i++){
			stk.push_back(a[i]);
		}
		sort(stk.begin(), stk.end());
		
		deque<vector<int>> soapy;
		deque<int> last;
		
		for(int i = 0; i < x; i++){
			auto it = upper_bound(all(last), a[i]);
			if(it == last.end()){
				// create new stack
				soapy.push_back({a[i]});
				last.push_back(a[i]);
			}
			else{
				int idx = it - last.begin();
				soapy[idx].push_back(a[i]);
				last[idx] = a[i];
			}
			
			while(!soapy.empty() && soapy[0].back() == stk.front()){
				soapy[0].pop_back();
				stk.pop_front();
				if(soapy[0].empty()){
					soapy.pop_front();
					last.pop_front();
				}
				if(!last.empty()){
					last[0] = soapy[0].back();
				}
				
			}
		}
		return stk.empty();
		
	};
	int l = 1, r = n + 1;
	while(l < r - 1){
		int mid = (l + r) / 2;
		if(check(mid)){
			l = mid;
		}
		else r = mid;
	}
	cout << l << "\n";
}
