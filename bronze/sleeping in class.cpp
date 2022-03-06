#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n; cin>>n;
	vector<int> a(n);
	for(int& i: a)cin>>i;
	int total = 0;
	for(int i: a){
		total += i;
	}
	
	set<int> factors;
	for(int i = 1; i * i <= total; i++){
		if(total % i == 0){
			factors.insert(i);
			factors.insert(total/i);
		}
	}
	if(total == 0){
		cout<<0<<endl;
		return;
	}
	int ans = n-1;
	for(int x: factors){
		int sum = 0;
		int operations = 0;
		int consec = 0;
		bool ok = true;
		for(int i = 0; i < n; i++){
			sum += a[i];
			consec++;
			if(sum > x){
				ok = false;
				break;
			}
			if(sum == x){
				sum = 0;
				operations += consec-1;
				consec = 0;
			}
		}
		//cout<<operations<<" "<<x<<endl;
		if(ok)ans = min(ans,operations);
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}

