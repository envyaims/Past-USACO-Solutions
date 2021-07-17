// Problem: Problem 1. Diamond Collector
// Contest: USACO - USACO 2016 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=639
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// ALL TEST CASES PASSED 7/16

#include <bits/stdc++.h>

using namespace std;



void solve(){
	ifstream fin("diamond.in");
	ofstream fout("diamond.out");
	int output = 1;
	int n,k;
	fin>>n>>k;
	int nums[n];
	for(int i = 0; i < n; i++){
		fin>>nums[i];
	}
	sort(nums,nums+n);
	for(int i = 0; i < n-1; i++){
		int count = 1;
		for(int j = i+1; j < n; j++){
			if(nums[j]- nums[i] <= k){
				count++;
			}
		}
		output = max(output,count);
	}
	fout<<output;
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
