#include <bits/stdc++.h>
using namespace std;
#define int long long

main(){
	int n; cin>>n;
	string s; cin>>s;
	vector<vector<int>> cows(2);
	for(int i = 0; i < n; i++){
		s[i] == 'G' ? cows[0].push_back(i) : cows[1].push_back(i);
	}
	int ans = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < cows[i].size(); j++){
			int lft = -1, rgt = n;
			if(j)lft = cows[i][j-1];
			if(j < cows[i].size()-1)rgt = cows[i][j+1];
			int l = cows[i][j]-lft-1;
			int r = rgt-cows[i][j]-1;
			ans += (l+1)*(r+1)-1;
			if(l)ans--;
			if(r)ans--;
		}
	}
	printf("%lld",ans);
	
}
