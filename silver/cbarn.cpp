// Author: envy
// Problem: Problem 1. Circular Barn from USACO - USACO 2016 February Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=618
// Limits: 4000 ms, 256 MB
// Attempted: 2021-10-31 12:55:25 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
int n; 
vector<int> cows;

void update(priority_queue<int>& pq){
	vector<int> elements;
	while(!pq.empty()){
		elements.push_back(pq.top()+1);
		pq.pop();
	}
	debug(elements);
	for(int i: elements){
		pq.push(i);
	}
}
int tryindex(int start){
	priority_queue<int> pq;
	int cnt = 0;
	for(int i = start; i < n+start; i++){
		for(int j = 0; j < cows[i%n]; j++){
			pq.push(0);
		}
		if(!pq.empty()){
			int front = pq.top();
			pq.pop();
			cnt += front*front;
		}
		update(pq);
	}
	if(pq.empty()){
		return cnt;
	}
	else return 1e9;
}

main(){
	freopen("cbarn.in","r",stdin);
	freopen("cbarn.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cows.resize(n);
	for(int i = 0; i < n; i++){
		cin>>cows[i];
	}
	
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		ans = min(ans,tryindex(i));
	}
	cout<<ans;
	
	
}
