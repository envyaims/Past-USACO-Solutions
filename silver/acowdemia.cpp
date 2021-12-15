// Author: envy <3 uwu
// Problem: Problem 3. Acowdemia
// Attempted: 2021-12-15 17:15:38 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
int n,k,l;
vector<int> a;

bool check(int x){
	int idx = lower_bound(a.begin(),a.end(),x) - a.begin();
	int cur = k*l;
	int alr = n-idx;
	int cost = 0;
	for(int i = idx-1; i >= idx-(x-alr); i--){
		if(i < 0)return false;
		cur -= max(0LL,x-a[i]);
		if(x-a[i] > k)return false;
	}
	return cur >= 0;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>l;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int L = 0, r = 1e9;
	while(L < r-1){
		int mid = (L+r)/2;
		if(check(mid)){
			L = mid;
		}
		else r = mid;
	}
	printf("%d",L);
	
}
