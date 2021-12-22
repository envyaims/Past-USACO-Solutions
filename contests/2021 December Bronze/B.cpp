#include <bits/stdc++.h>
using namespace std;
#define int long long

main(){
	int n; cin>>n;
	vector<int> wish(n), stall(n);
	for(int& i: wish)cin>>i;
	for(int& i: stall)cin>>i;
	vector<int> diff(n);
	for(int i = 0; i < n; i++){
		diff[i] = wish[i] - stall[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		while(diff[i] != 0){
			int atleast = diff[i];
			int nxt = i;
			for(int j = i+1; j < n; j++){
				if(diff[j] > 0 && atleast > 0){
					atleast = min(atleast,diff[j]);
					nxt = j;
				}
				else if(diff[j] < 0 && atleast < 0){
					atleast = max(atleast,diff[j]);
					nxt = j;
				}
				else break;
			}
			for(int j = i; j <= nxt; j++){
				diff[j] -= atleast;
			}
			ans += abs(atleast);
		}
	}
	
	printf("%lld",ans);
}