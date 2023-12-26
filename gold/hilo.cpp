// keqing <3
// Problem: Problem 2. HILO
// Attempted: 2023-12-25 19:17:47 EST

#include <bits/stdc++.h>

#ifndef LOCAL
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
#define all(x) x.begin(), x.end()

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(int& i: a) cin >> i;

	
	set<int> s = {0, n + 1};
	vector<pair<int, int>> hi_segs, lo_segs;
	
	for(int i = 0; i < n; i++){
		// who will say hi?
		// for all x < a[i] and x > previous lower
		auto it = prev(s.lower_bound(a[i]));
		hi_segs.push_back({*it, a[i] - 1});
		// who will say lo?
		// for all x >= a[i] and x < next greater
		it = s.lower_bound(a[i]);
		lo_segs.push_back({a[i], *it - 1});
		s.insert(a[i]);
	}
	debug(hi_segs, lo_segs);
	vector<vector<int>> hi_open(n + 5), hi_close(n + 5), lo_open(n + 5), lo_close(n + 5);
	for(int i = 0; i < n; i++){
		hi_open[hi_segs[i].first].push_back(i);
		hi_close[hi_segs[i].second + 1].push_back(i);
		lo_open[lo_segs[i].first].push_back(i);
		lo_close[lo_segs[i].second + 1].push_back(i);
	}
	
	// two can't have hi and lo at the same time
	set<int> track;
	vector<bool> is_hi(n), matched(n);
	int ans = 0;
	
	auto ins = [&](int x, bool hi){
		auto it = track.lower_bound(x);
		if(hi){
			if(it != track.end() && !is_hi[*it]){
				if(matched[*it]){
					// hi hi lo
					auto prv = prev(it);
					matched[*prv] = 0;
				}
				else{
					// lo hi lo
					ans++;
				}
				matched[*it] = matched[x] = 1;
			}
		}
		else{
			if(it != track.begin() && is_hi[*prev(it)]){
				--it;
				if(matched[*it]){
					auto nxt = next(it);
					matched[*nxt] = 0;
				}
				else{
					ans++;
				}
				matched[*it] = matched[x] = 1;
			}
		}
		track.insert(x);
	};
	
	auto rem = [&](int x, bool hi){
		track.erase(x);
		auto it = track.lower_bound(x);
		if(hi){
			if(matched[x]){
				// hi hi lo
				if(it != track.begin() && is_hi[*prev(it)]){
					assert(!matched[*prev(it)]);
					matched[*prev(it)] = 1;
				}
				else{
					matched[*it] = 0;
					--ans;
				}
			}
		}
		else{
			if(matched[x]){
				// hi lo lo
				if(it != track.end() && !is_hi[*it]){
					assert(!matched[*it]);
					matched[*it] = 1;
				}
				else{
					matched[*prev(it)] = 0;
					--ans;
				}
			}
		}
		matched[x] = 0;
	};

	
	for(int i = 0; i <= n; i++){
		for(int j: hi_close[i]){
			rem(j, 1);
		}
		for(int j: lo_close[i]){
			rem(j, 0);
		}
		for(int j: hi_open[i]){
			ins(j, 1);
			is_hi[j] = 1;
		}
		for(int j: lo_open[i]){
			ins(j, 0);
			is_hi[j] = 0;
		}
		cout << ans << "\n";
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
