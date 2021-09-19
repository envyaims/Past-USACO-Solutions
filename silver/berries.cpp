/*
author: envy
solved on 9/19/2021
*/
#include <bits/stdc++.h>
using namespace std;

#define print(x) cout<<x<<endl;

int n,k;
vector<int> nums;
int prevans = 0;

void check(int x){
	// we give elsie x amount for k/2 baskets
	// therefore bessie can only take a maxinum of x elements
	vector<int> berries(nums.begin(),nums.end());
	
	int groups = 0;
	for(int i = 0; i < n; i++){
		if(berries[i] >= x){
			int groupscanmake = berries[i]/x;
			int addamt = min(groupscanmake,k/2 - groups);
			groups += addamt;
			berries[i] -= addamt * x;			
		}
		if(groups == k/2){
			break;
		}
	}
	if(groups < k/2){
		return;
	}
	int bessgroups = 0;
	int bessamt = 0;
	priority_queue<int> leftovers;
	for(int i : berries)leftovers.push(i);
	while(bessgroups < k/2 and !leftovers.empty()){
		int front = leftovers.top();
		leftovers.pop();
		if(front >= x){
			int groupscanmake = front/x;
			int addamt = min(groupscanmake,k/2-bessgroups);
			bessgroups += addamt;
			bessamt += addamt*x;
			leftovers.push(front % x);
		}
		else{
			bessgroups++;
			bessamt += front;
		}
	}
	prevans = max(prevans,bessamt);
	
}

signed main(){
	freopen("berries.in","r",stdin);
	freopen("berries.out","w",stdout);
	cin>>n>>k;
	nums.resize(n);
	for(int i = 0; i < n; i++){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end(),greater<int>());

	for(int i = 1; i <= 1000; i++){
		check(i);
	}
	print(prevans);
}