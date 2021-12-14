// Author: envy <3 uwu
// Problem: Problem 1. Dance Mooves
// Attempted: 2021-12-13 20:22:35 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
vector<int> pos[100001];
int lastpos[100001];
int comp[100001];
int ans[100001];

void dfs(int node){
	int cur = lastpos[node];
	while(cur != node){
		for(int i: pos[cur]){
			pos[node].push_back(i);
		}
		comp[cur] = node;
		cur = lastpos[cur];
	}
	
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,K;
	cin>>n>>K;
	vector<int> cows(n+1);
	for(int i = 1; i <= n; i++){
		cows[i] = i;
		pos[i].push_back(i);
		lastpos[cows[i]] = i;
		comp[i] = i;
	}
	
	for(int i = 0; i < K; i++){
		int a,b; cin>>a>>b;
		swap(cows[a],cows[b]);
		pos[cows[a]].push_back(a);
		pos[cows[b]].push_back(b);
		lastpos[cows[a]] = a;
		lastpos[cows[b]] = b;
		
	}
	
	for(int i = 1; i <= n; i++){
		if(comp[i] == i){
			dfs(i);
			vector<bool> has(n+1);
			for(int j: pos[i]){
				if(!has[j]){
					has[j] = true;
					ans[i]++;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		printf("%d\n",ans[comp[i]]);
	}
	
}
