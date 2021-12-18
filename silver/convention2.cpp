// Author: envy <3 uwu
// Problem: Problem 2. Convention II
// Attempted: 2021-12-17 19:29:03 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
main(){
	ifstream cin("convention2.in");
	ofstream cout("convention2.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	minpq<array<int,3>> pq, now;
	for(int i = 0; i < n; i++){
		int a,t; cin>>a>>t;
		pq.push({a,i,t});
	}
	
	int ans = 0;
	int time = 0;
	
	auto more = [&](int t){
		while(!pq.empty() && pq.top()[0] <= t){
				array<int,3> info = pq.top();
				pq.pop();
				now.push({info[1],info[2],info[0]});
				// [s,t,a];
		}
	};
	
	while(!pq.empty()){
		time = pq.top()[0];
		more(time);
		while(!now.empty()){
			array<int,3> eat = now.top();
			now.pop();
			debug(time,eat);
			ans = max(ans,time-eat[2]);
			time += eat[1];
			more(time);
		}

		
	}
	cout<<ans;
	
	
}
