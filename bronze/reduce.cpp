// Author: envy
// Problem: Problem 3. Field Reduction from USACO - USACO 2016 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=641
// Limits: 4000 ms, 256 MB
// Attempted: 2021-10-31 18:26:34 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long

#define mp make_pair
#define S second
#define F first


bool sorty(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int area(vector<pair<int,int>>& pt, int l, int r){
	int minx = 1e18, miny = 1e18, maxx = 0, maxy = 0;
	for(int i = l; i < r; i++){
		minx = min(minx,pt[i].F);
		maxx = max(maxx, pt[i].F);
		miny = min(miny,pt[i].S);
		maxy = max(maxy,pt[i].S);
	}
	return (maxx-minx)*(maxy-miny);
	
}
main(){
	freopen("reduce.in","r",stdin);
	freopen("reduce.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<pair<int,int>> xpoints(n), ypoints(n);
	for(int i = 0; i < n; i++){
		int a,b; cin>>a>>b;
		xpoints[i] = mp(a,b);
		ypoints[i] = mp(a,b);
	}
	sort(xpoints.begin(),xpoints.end());
	sort(ypoints.begin(),ypoints.end(),sorty);
	int ans = 1e18;
	for(auto i: {xpoints,ypoints}){
		ans = min(ans,area(i,0,n-1));
		ans = min(ans,area(i,1,n));
	}
	cout<<ans;
	
	
	
}