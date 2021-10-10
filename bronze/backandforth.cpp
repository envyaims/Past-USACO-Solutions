// Author: envy
// Problem: Problem 3. Back and Forth from USACO - USACO 2018 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=857
// Limits: 4000 ms, 256 MB
// Attempted: 2021-10-10 18:42:45 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T> void max_self(T& a, T b){a = max(a,b);}
template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;
using secondpq = priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll; const ll INF = 1e18; const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};
#define int long long
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}

vector<int> bucket(20);
set<int> ans;

void oddday(int tank1, int tank2, vector<bool> atone, vector<bool> attwo, int day);
void evenday(int tank1, int tank2, vector<bool> atone, vector<bool> attwo, int day);

void oddday(int tank1, int tank2, vector<bool> atone, vector<bool> attwo, int day){
	for(int i = 0; i < 20; i++){
		if(attwo[i]){
			atone[i] = true;
			attwo[i] = false;
			if(day == 5){
				ans.insert(tank1 + bucket[i]);
			}
			else{
				evenday(tank1 + bucket[i],tank2 - bucket[i],atone,attwo,day+1);
			}
			atone[i] = false;
			attwo[i] = true;
		}
	}
}

void evenday(int tank1, int tank2, vector<bool> atone, vector<bool> attwo, int day){
	for(int i = 0; i < 20; i++){
		if(atone[i]){
			atone[i] = false;
			attwo[i] = true;
			oddday(tank1 - bucket[i],tank2 + bucket[i],atone,attwo,day+1);
			atone[i] = true;
			attwo[i] = false;
		}
	}
	
}
void doStuff(){
	freopen("backforth.in","r",stdin);
	freopen("backforth.out","w",stdout);
	for(int& i: bucket)cin>>i;
	// tank 1 from 0-9
	// tank2 from 10-19
	vector<bool> atone(20,false), attwo(20,false);
	for(int i = 0; i < 10; i++){
			atone[i] = true;
		}
	for(int i = 10; i < 20; i++){
			attwo[i] = true;
	}
	evenday(1000,1000,atone,attwo,2);
	print(ans.size());
	
		
		
	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){
		doStuff();
	}
}
