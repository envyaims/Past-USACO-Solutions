// Author: envy
// Problem: Problem 2. Milk Measurement from USACO - USACO 2017 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=763
// Limits: 4000 ms, 256 MB
// Attempted: 2021-09-18 07:48:10 EST

#ifndef LOCAL
#define debug(...) 0
#include <bits/stdc++.h>
#else
#include "C:\programmingfunnyxd\debug.cpp"
#include "C:\programmingfunnyxd\includeordie.h"
#endif
using namespace std;
inline namespace readio { const int BSZ = 1<<15; char ibuf[BSZ]; int ipos, ilen;char nc() {if (ipos == ilen) {ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);if (!ilen) return EOF;}return ibuf[ipos++];}
template<class T> void ri(T& x) {char ch; int sgn = 1;while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');x *= sgn;}
template<class T> void rc(T& x){ x = nc();while(isspace(x))x = nc();}template<class T, class... Ts> void ri(T& t, Ts&... ts) {ri(t);ri(ts...);}
template<class str>void rs(str& x) { char ch; while (isspace(ch = nc()));do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);}}
template<typename T> void max_self(T& a, T b){a = max(a,b);}template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;template<typename T> using maxpq = priority_queue<T>;
using secondpq = priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond>;
typedef long long ll; const ll INF = 1e18; const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define bpop(x) __builtin_popcount(x)
#define fillarr(arr,n,am) fill(arr[0],arr[n],am)
#define readarr(arr) for(int &i: arr)ri(i);
#define readchararr(arr)for(int &i: arr)rc(i);
#define readgrid(arr, n, m)for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)ri(arr[i][j]);
#define readchargrid(arr, n, m)for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)rc(arr[i][j]);
const int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
#define int long long // fight me
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b/=2;a=(a*a)%m;}return ans;}

void doStuff(){
	freopen("measurement.in","r",stdin);
	freopen("measurement.out","w",stdout);
	int n,g; cin>>n>>g;
	vector<array<int,3>> nums(n);
	map<int,int> cows;
	map<int,int> ids;
	vector<bool> maxcows(100001,true);
	int order = 1;
	for(int i = 0; i < n; i++){
		int day, id, change; 
		cin>>day>>id>>change;
		if(ids[id] == 0){
			ids[id] = order;
			id = order;
			order++;
		}
		else id = ids[id];
		cows[id] = g;
		nums[i] = {day,id,change};
	}
	sort(all(nums));
	debug(cows);
	
	int maxn = g;
	int maxcnt = 100000;
	int ans = 0;
	for(int i = 0 ; i < n; i++){
		int id = nums[i][1];
		int change = nums[i][2];
		cows[id] += change;
		if(cows[id] > maxn){
			if(maxcnt == 1 and maxcows[id]){
				maxn = cows[id];
			}
			else{
				fill(all(maxcows),false);
				maxn = cows[id];
				ans++;
				maxcnt = 1;
				maxcows[id] = true;
			}
		}
		else if(cows[id] == maxn){
			ans++;
			maxcnt++;
			maxcows[id] = true;
		}
		else{
			if(maxcnt == 1 and maxcows[id]){
				maxn = 0;
				maxcnt = 0;
				fill(all(maxcows),false);
				for(auto j: cows){
					maxn = max(maxn,j.S);
				}
				for(auto j: cows){
					if(j.S == maxn){
						maxcows[j.F] = true;
						maxcnt++;
					}
				}
				if(maxcnt == 1 and maxcows[id]){
					
				}
				else{
					ans++;
					
				}

			}
			else{
				if(maxcows[id]){
					ans++;
					maxcows[id] = false;
					maxcnt--;
				}
			}
		}
	}
	print(ans);
	
	
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);int t = 1;
	// ri(t);
	while(t--)doStuff();
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}