// note: this code doesnt get ac for two of the test cases :(

#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;
#define F first
#define S second
#define all(x) x.begin(), x.end()
using ll = long long;


void solve(){
	int n;
	scanf("%d", &n);
	int endx, endy;
	scanf("%d %d",&endx,&endy);
	vector<pair<ll,ll>> a(n);
	for(int i = 0; i < n; i++){
		scanf("%lld %lld",&a[i].F,&a[i].S);
	}
	
	auto subsetsums = [&](int l, int r) -> vector<array<ll,3>>{
		int len = r-l+1;
		vector<array<ll,3>> ret;
		for(int i = 0; i < (1<<len); i++){
			ll x = 0, y = 0;
			for(int j = 0; j < len; j++){
				if(i & (1<<j)){
					x += a[l + j].F;
					y += a[l + j].S;
				}
			}
			ret.push_back({x,y,__builtin_popcount(i)});
		}
		return ret;
	};
	
	vector<array<ll,3>> left = subsetsums(0, n/2-1), right = subsetsums(n/2,n-1);
	
	auto csort = [&](auto a, auto b){
		if(a[0] != b[0])return endx - a[0] > endx - b[0];
		return endy - a[1] > endy - b[1];
	};
	sort(left.begin(),left.end(),csort);
	sort(right.rbegin(),right.rend());
	
	vector<ll> ans(n+1);
	ll r = 0;
	
	
	for(auto i: left){
		ll dx = endx - i[0], dy = endy - i[1];
		debug(dx,dy);
		while(r < (ll)right.size() && (right[r][0] > dx || right[r][1] > dy)){
			if(right[r][0] < dx)break;
			debug(right[r]);
			r++;
		}
		//debug(r);
		ll curr = r;
		while(r < (ll)right.size() && right[r][0] == dx && right[r][1] == dy){
			ans[i[2] + right[r][2]]++;
			r++;
		}
		r = curr;
	}
	for(int i = 1; i <= n; i++){
		printf("%lld\n",ans[i]);
	}
	
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
}

