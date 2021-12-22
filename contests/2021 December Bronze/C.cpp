#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
char grid[50][50];
int ans = 0;

// dir == 0 is down, dir == 1 is right
void recurse(int r, int c, int know, bool dir, bool steps = 0){
	if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == 'H')return;
	if(r == n-1 && c == n-1){
		ans++;
		return;
	}
	if(know < k && steps){
		if(dir){
			recurse(r,c+1,know+1,!dir, 1);
		}
		else{
			recurse(r+1,c,know+1,!dir, 1);
		}
	}
	if(dir){
			recurse(r+1,c,know,dir, 1);
		}
		else{
			recurse(r,c+1,know,dir, 1);
		}
}

void test_case(){
	ans = 0;
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>grid[i][j];
		}
	}
	
	recurse(0,0,0,0);
	recurse(0,0,0,1);
	printf("%lld\n",ans);
	
}

main(){
	int t; cin>>t;
	while(t--){
		test_case();
	}
}