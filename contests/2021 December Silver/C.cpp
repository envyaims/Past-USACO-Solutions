#include <bits/stdc++.h>
using namespace std;
#define int long long
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;
	vector<int> l(5001), r(5001);
	for(int i = 0; i < n; i++){
		int curl, curr; cin>>curl>>curr;
		l[curl]++;
		r[curr]++;

	}
	vector<int> pref(100001);
	for(int i = 0; i <= m; i++){
		pref[2*i] += l[i]*l[i];
		pref[2*i+1] -= r[i]*r[i];
	}
	for(int i = 0; i <= m; i++){
		for(int j = i+1; j <= m; j++){
			pref[i+j] += 2*l[i]*l[j];
			pref[i+j+1] -= 2*r[i]*r[j];
		}
	}
	for(int i = 1; i <= 2*m; i++){
		pref[i] += pref[i-1];
	}
	for(int i = 0; i <= 2*m; i++){
		printf("%lld\n",pref[i]);
	}
}