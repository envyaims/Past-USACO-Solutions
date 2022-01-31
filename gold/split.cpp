#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;
#define int long long

struct pt{
	int x,y;
};

void solve(){
	int n; cin>>n;
	vector<pt> points(n);
	multiset<int> globalx, globaly, leftx, lefty, rightx, righty;
	for(int i = 0; i < n; i++){
		cin>>points[i].x>>points[i].y;
		globalx.insert(points[i].x);
		globaly.insert(points[i].y);
	}
	sort(points.begin(),points.end(),[&](auto a, auto b){
		if(a.x != b.x)return a.x < b.x;
		else return a.y < b.y;
	});
	int x1,x2,y1,y2;
	x1 = *globalx.begin();
	x2 = *globalx.rbegin();
	y1 = *globaly.begin();
	y2 = *globaly.rbegin();
	int original = (x2-x1) * (y2-y1);
	int ans = 0;
	for(int times = 0; times < 2; times++){
		rightx = globalx;
		righty = globaly;
		leftx.clear();
		lefty.clear();
		for(int i = 0; i < n; i++){
			leftx.insert(points[i].x);
			lefty.insert(points[i].y);
			rightx.erase(rightx.find(points[i].x));
			righty.erase(righty.find(points[i].y));
			
			int xdiff = *leftx.rbegin() - *leftx.begin();
			int ydiff = *lefty.rbegin() - *lefty.begin();
			int areaL = xdiff * ydiff;
			if(!rightx.empty()){
				xdiff = *rightx.rbegin() - *rightx.begin();
				ydiff = *righty.rbegin() - *righty.begin();
				int areaR = xdiff * ydiff;
				ans = max(ans,original-areaL-areaR);
			}
		}
		sort(points.begin(),points.end(),[&](auto a, auto b){
			if(a.y != b.y)return a.y < b.y;
			else return a.x < b.x;
		});
	}
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin>>t;
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	while(t--){
		solve();
	}
}

