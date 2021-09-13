// Author: envy
// Problem: Problem 3. Where's Bessie? from USACO - USACO 2017 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=740
// Limits: 4000 ms, 256 MB
// Attempted: 2021-09-12 20:28:30 EST

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
typedef priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond> secondpq;
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

int n;
char grid[20][20];

struct PCLs{
	int left, right, up, down;
};

bool inside(PCLs& a, PCLs& b){
		return a.left >= b.left && a.right <= b.right && a.up >= b.up && a.down <= b.down;
	}
	
void floodfill(int r, int c, int x1, int x2, int y1, int y2, vector<vector<bool>>& visited, char color){
	if(r < x1 || r > x2 || c < y1 || c > y2){
		return;
	}
	if(grid[r][c] != color || visited[r][c])return;
	visited[r][c] = true;
	for(int i = 0; i < 4; i++){
		floodfill(r + dx[i], c + dy[i],x1,x2,y1,y2,visited,grid[r][c]);
	}
}
bool check(int x1, int x2, int y1, int y2){
	// check if more than 2 colors
	set<char> colors;
	for(int i = x1; i <= x2; i++){
		for(int j = y1; j <= y2; j++){
			colors.insert(grid[i][j]);
		}
	}
	if(colors.size() != 2){
		return false;
	}
	
	char firstgrid = *colors.begin();
	vector<vector<bool>> visited(20,vector<bool>(20,false));
	int regions1 = 0;
	int regions2 = 0;
	for(int i = x1; i <= x2; i++){
		for(int j = y1; j <= y2; j++){
			if(!visited[i][j]){
				if(grid[i][j] == firstgrid){
					regions1++;
				}
				else regions2++;
				floodfill(i,j,x1,x2,y1,y2,visited,grid[i][j]);
			}
		}
	}
	if(regions1 == 1 && regions2 > 1){
		return true;
	}
	if(regions1 > 1 && regions2 == 1){
		return true;
	}
	return false;
}

void doStuff(){
	ri(n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			rc(grid[i][j]);
		}
	}
	
	vector<PCLs> valids;
	for(int x1 = 0; x1 < n; x1++){
		for(int x2 = x1; x2 < n; x2++){
			for(int y1 = 0; y1 < n; y1++){
				for(int y2 = y1; y2 < n; y2++){
					if(check(x1,x2,y1,y2)){
						PCLs curr = {x1,x2,y1,y2};
						// bool insideany = false;
						// for(PCLs i: valids){
							// if(inside(i,curr) || inside(curr,i)){
								// insideany = true;
								// break;
							// }
// 							
						// }
						// if(!insideany){
							// ans++;
						// }
						valids.push_back(curr);
						// cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
					}
				}
			}
		}
	}
	int ans = valids.size();
	debug(valids.size());
	for(int i = 0; i < valids.size(); i++){
		for(int j = 0; j < valids.size(); j++){
			if(i != j && inside(valids[i],valids[j])){
				ans--;
				break;
			}
		}
	}
	cout<<ans;
	
	
}

signed main(){
	freopen("where.in","r",stdin);
	freopen("where.out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);int t = 1;
	// ri(t);
	while(t--)doStuff();
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}