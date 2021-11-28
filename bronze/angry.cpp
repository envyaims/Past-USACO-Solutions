// Author: envy
// Problem: Problem 2. Angry Cows
// Attempted: 2021-11-26 20:43:21 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
main(){
	ifstream cin("angry.in");
	ofstream cout("angry.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<int> nums(n);
	for(int& i: nums)cin>>i;
	sort(nums.begin(),nums.end());
	int ans = 0;
	for(int i = 0; i < n-1; i++){
		int curr = nums[i];
		int idx = i;
		for(int t = 1;;t++){
			int bound = curr - t;
			int curridx = idx;
			for(int j = idx; j >= 0; j--){
				if(nums[j] >= bound){
					curr = nums[j];
					curridx = j;
				}
			}
			if(curridx  == idx){
				break;
			}
			else{
				idx = curridx;
			}
		}
		
		curr = nums[i];
		int idx2 = i;
		for(int t = 1;; t++){
			int bound = curr+t;
			int curridx = idx2;
			for(int j = idx2; j < n; j++){
				if(nums[j] <= bound){
					curr = nums[j];
					curridx = j;
				}
			}
			if(curridx == idx2)break;
			else idx2 = curridx;
		}
		
		ans = max(ans, (i-idx) + (idx2-i) + 1);
	}
	cout<<ans;
}
