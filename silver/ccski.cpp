// Problem: Problem 2. Cross Country Skiing
// Contest: USACO - USACO 2014 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=380
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: ccski.in 
// Output: ccski.out   
// Attempted: 2021-08-20 17:33:03 EST
// AC

#include <bits/stdc++.h>
using namespace std;

template<typename T>
using reversepq = priority_queue<T, vector<T>, greater<T>>;

typedef long long ll;
const ll INF = 1e18;
const int MOD = 1e9+7, MN = 1e5 + 5;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define bpop(x) __builtin_popcount(x)
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};

int grid[501][501];
vector<pair<int,int>> waypoints;
int waycount = 0;
int n,m; 

void floodfill(int r, int c, vector<vector<bool>>& visited, int mid){
	if(r < 0 || r >= n || c < 0 || c >= m){
		return;
	}
	if(visited[r][c])return;
	visited[r][c] = true;
	
	for(int i = 0; i < 4; i++){
		int row = r + dx[i];
		int col = c + dy[i];
		if(abs(grid[row][col] - grid[r][c]) < mid){
			floodfill(row,col,visited,mid);
		}
	}
}

bool check(int x, vector<vector<bool>>& visited){
	floodfill(waypoints[0].F, waypoints[0].S, visited, x);
	for(int i = 1; i < waycount; i++){
		if(!visited[waypoints[i].F][waypoints[i].S]){
			return false;
		}
	}
	return true;
}

void doStuff(){
	freopen("ccski.in","r",stdin);
	freopen("ccski.out","w",stdout);
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>grid[i][j];
		}
	}
	for(int i= 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int a; cin>>a;
			if(a == 1){
				waypoints.pb(mp(i,j));
				waycount++;
			}
		}
	}
	
	int start = 0, end = 1e9;
	while(start < end-1){
		int mid = start + (end-start)/2;
		vector<vector<bool>> visited(n,vector<bool>(m,false));
		if(check(mid,visited)){
			end = mid;
		}
		else start = mid;
	}
	print(start);
	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
	// int t; ri(t);
	// while(t--){
		// doStuff();
	// }
    
    
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}

// you should actually read the stuff at the bottom and not submit the same wrong code

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* maybe just stop being dumb lol
*/
