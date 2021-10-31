// Author: envy
// Problem: Problem 2. Fruit Feast from USACO - USACO 2015 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=574
// Limits: 4000 ms, 256 MB
// Attempted: 2021-10-31 07:48:42 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
main(){
	freopen("feast.in","r",stdin);
	freopen("feast.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,a,b; cin>>t>>a>>b;
	vector<bool> canget(t+1), withwater(t+1);
	canget[0] = true;
	int ans = 0;
	for(int i = min(a,b); i <= t; i++){
		for(int j: {a,b}){
			if(i-j >= 0 && canget[i-j]){
				canget[i] = true;
				withwater[i/2] = true;
				ans = i;
				break;
			}
		}
	}	
	withwater[0] = true;
	for(int i = min(a,b); i <= t; i++){
		for(int j: {a,b}){
			if(i-j >= 0 and withwater[i-j]){
				withwater[i] = true;
				ans = max(ans,i);
				break;
			}
		}
	}
	cout<<ans;

}