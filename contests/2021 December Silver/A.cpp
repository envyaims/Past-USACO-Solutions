#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k,m,n; cin>>k>>m>>n;
	vector<int> cows(m+1);
	vector<pair<int,int>> a(k+1);
	for(int i = 1; i <= k; i++){
		cin>>a[i].first>>a[i].second;
	}
	for(int i = 1; i <= m; i++){
		cin>>cows[i];
	}
	sort(a.begin(),a.end());
	sort(cows.begin(),cows.end());
	int idx = 1, cur = 0;
	while(idx <= k && a[idx].first < cows[1]){
		cur += a[idx].second;
		idx++;
	}
	vector<int> b;
	for(int i = 2; i <= m; i++){
		cur = 0;
		while(idx <= k && a[idx].first == cows[i-1]){
			idx++;
		}
		int newx = idx;
		while(newx <= k && a[newx].first < cows[i]){
			cur += a[newx].second;
			newx++;
		}
		int tempx = idx, sum = 0, maxn = 0;
		for(int j = idx; j < newx; j++){
			int dif = a[j].first*2-cows[i-1];
			dif = (dif+cows[i]+1)/2;
			while(tempx < newx && a[tempx].first < dif){
				sum += a[tempx].second;
				tempx++;
			}
			maxn = max(maxn,sum);
			sum -= a[j].second;
			
		}
		b.push_back(maxn);
		b.push_back(cur-maxn);
		idx = newx;
		
	}
	while(idx <= k && a[idx].first == cows[m]){
		idx++;
	}
	cur = 0;
	while(idx <= k){
		cur += a[idx].second;
		idx++;
	}
	b.push_back(cur);
	int ans = 0;
	sort(b.begin(),b.end());
	while(n){
		ans += b.back();
		b.pop_back();
		n--;
	}
	printf("%lld",ans);
	
	
	
	
	
}