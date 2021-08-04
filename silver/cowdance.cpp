// Problem: Problem 1. Cow Dance Show
// Contest: USACO - USACO 2017 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=690
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file cowdance.in  
// Output: file cowdance.out  
// Attempted: 2021-08-03 11:39:49 EST

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
const ll INF = 1e18;
const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())

int n,t;
vector<int> nums;

bool check(int x){
	int time = 0;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 0; i < n; i++){
		if(pq.size() == x){
			time = pq.top();
			pq.pop();
		}
		if(time + nums[i] > t){
			return false;
		}
		pq.push(time + nums[i]);
	}
	return true;
}

int firstTrue(int start, int end, function<bool(int)> f){
	for(end++; start < end; ){
		int mid = start + (end-start)/2;
		if(f(mid)) end = mid;
		else start = mid+1;
	}
	return start;
}

void doStuff(){
	freopen("cowdance.in","r",stdin);
	freopen("cowdance.out","w",stdout);
	ri(n,t);
	for(int i = 0; i < n; i++){
		int a; ri(a);
		nums.pb(a);
	}
	
	cout<<firstTrue(1,n,check);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
