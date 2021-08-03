#include <bits/stdc++.h>
using namespace std;

inline namespace fastio {
	const int BSZ = 1<<15; 
	char ibuf[BSZ]; int ipos, ilen;
	char nc() {
		if (ipos == ilen) {
			ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);
			if (!ilen) return EOF;
		}
		return ibuf[ipos++];
	}
	template<class T> void ri(T& x) { // read int or ll
		char ch; int sgn = 1;
		while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
		x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
		x *= sgn;
	}
	template<class T> void rc(T& x){ // read char
		x = nc();
		while(isspace(x)){
			x = nc();
		}
	}
	template<class T, class... Ts> void ri(T& t, Ts&... ts) { 
		ri(t); ri(ts...); } // read ints
	template<class str>void rs(str& x) { // read str
		char ch; while (isspace(ch = nc()));
		do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);
	}
}

typedef long long ll;
const int INF = 1e18, MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())


void doStuff(){
	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);
	int n; ri(n);
	vector<ll> nums(n);
	for(int i = 0; i < n; i++){
		ri(nums[i]);
	}
	sort(all(nums));
	int ans = 1;
	for(int i = 0; i < n; i++){
		int ap = i;
		int bp = i;
		for(int t = 1; ap < n-1; t++){
			if(nums[ap+1] <= nums[ap] + t){
				while(nums[ap+1] <= nums[ap] + t && ap < n-1){
					ap++;
				}
			}
			else break;
			
		}
		
		for(int t = 1; bp > 0; t++){
			if(nums[bp-1] >= nums[bp] - t){
				while(nums[bp-1] >= nums[bp] - t && bp > 0){
					bp--;
				}
			}
			else break;
		}
		ans = max(ans, (ap-i) + (i-bp) + 1);
	}
	
	print(ans);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
