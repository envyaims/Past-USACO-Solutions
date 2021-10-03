// Author: envy
// Problem: Problem 2. Bull in a China Shop from USACO - USACO 2016 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=640
// Limits: 4000 ms, 256 MB
// Attempted: 2021-10-03 07:07:37 EST

#ifndef LOCAL
#define debug(...) 0
#include <bits/stdc++.h>
#else
#include "C:\programmingfunnyxd\debug.cpp"
#include "C:\programmingfunnyxd\includeordie.h"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
inline namespace readio { const int BSZ = 1<<15; char ibuf[BSZ]; int ipos, ilen;char nc() {if (ipos == ilen) {ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);if (!ilen) return EOF;}return ibuf[ipos++];}
template<class T> void ri(T& x) {char ch; int sgn = 1;while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');x *= sgn;}
template<class T> void rc(T& x){ x = nc();while(isspace(x))x = nc();}template<class T, class... Ts> void ri(T& t, Ts&... ts) {ri(t);ri(ts...);}
template<class str>void rs(str& x) { char ch; while (isspace(ch = nc()));do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);}}
template<typename T> void max_self(T& a, T b){a = max(a,b);}template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;template<typename T> using maxpq = priority_queue<T>;
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
#define bpop(x) __builtin_popcount(x)
#define fillarr(arr,n,am) fill(arr[0],arr[n],am)
#define readarr(arr) for(int &i: arr)ri(i);
#define readchararr(arr)for(int &i: arr)rc(i);
#define readgrid(arr, n, m)for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)ri(arr[i][j]);
#define readchargrid(arr, n, m)for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)rc(arr[i][j]);
const int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}
int n, m;

char target[8][8];
char maybe[10][8][8];
vector<vector<vector<vector<char>>>> shifts(10);

void leftshifts(int id, vector<vector<char>> grid);
void rightshifts(int id, vector<vector<char>> grid);
void leftshifts(int id, vector<vector<char>> grid);
void downshifts(int id, vector<vector<char>> grid);

void debuggrid(int id){
	for(int g = 0; g < shifts[id].size(); g++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout<<shifts[id][g][i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

void printgrid(vector<vector<char>> grid){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<grid[i][j];
		}
		cout<<endl;
	}
}

void topshifts(int id, vector<vector<char>> grid){
	vector<vector<char>> modgrid = grid;
	
	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++){
			if(grid[r][c] == '#'){
				return;
			}
		}
		// shift everything to the top lol
		for(int i = 1; i < n; i++){
			for(int j = 0; j < n; j++){
				modgrid[i-1][j] = modgrid[i][j];
			}
		}
		// fill last row with space
		for(int j =0; j < n; j++){
			modgrid[n-1][j] = '.';
		}
		shifts[id].push_back(modgrid);
		leftshifts(id,modgrid);
		rightshifts(id,modgrid);
	}
}

void downshifts(int id, vector<vector<char>> grid){
	vector<vector<char>> modgrid = grid;
	
	for(int r = n-1; r >= 0; r--){
		for(int c = 0; c < n; c++){
			if(grid[r][c] == '#'){
				return;
			}
		}
		// shift everything to the down lol
		for(int i = n-2; i >= 0; i--){
			for(int j = 0; j < n; j++){
				modgrid[i+1][j] = modgrid[i][j];
			}
		}
		// fill first col with space
		for(int j =0; j < n; j++){
			modgrid[0][j] = '.';
		}
		shifts[id].push_back(modgrid);
		leftshifts(id,modgrid);
		rightshifts(id,modgrid);
	}
}

void leftshifts(int id, vector<vector<char>> grid){
	vector<vector<char>> modgrid = grid;
	
	for(int c = 0; c < n; c++){
		for(int r = 0; r < n; r++){
			if(grid[r][c] == '#'){
				return;
			}
		}
		// shift everything to the left lol
		for(int j = 1; j < n; j++){
			for(int i = 0; i < n; i++){
				modgrid[i][j-1] = modgrid[i][j];
			}
		}
		// fill right col with space
		for(int j = 0; j < n; j++){
			modgrid[j][n-1] = '.';
		}
		shifts[id].push_back(modgrid);
		// topshifts(id,modgrid);
		// downshifts(id,modgrid);
	}
}

void rightshifts(int id, vector<vector<char>> grid){
	vector<vector<char>> modgrid = grid;
	
	for(int c = n-1; c >= 0; c--){
		for(int r = 0; r < n; r++){
			if(grid[r][c] == '#'){
				return;
			}
		}
		// shift everything to the right lol
		for(int j = n-2; j >= 0; j--){
			for(int i = 0; i < n; i++){
				modgrid[i][j+1] = modgrid[i][j];
			}
		}
		// fill left row with space
		for(int j = 0; j < n; j++){
			modgrid[j][0] = '.';
		}
		shifts[id].push_back(modgrid);
		// topshifts(id,modgrid);
		// downshifts(id,modgrid);
	}
}


void doStuff(){
	freopen("bcs.in","r",stdin);
	freopen("bcs.out","w",stdout);
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>target[i][j];
		}
	} 
	
	for(int g = 0; g < m; g++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin>>maybe[g][i][j];
			}
		}
	}
	for(int g = 0; g < m; g++){
		vector<vector<char>> grid(n,vector<char>(n));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				grid[i][j] = maybe[g][i][j];
			}
		}
		shifts[g].pb(grid);
		topshifts(g,grid);
		downshifts(g,grid);
		leftshifts(g,grid);
		rightshifts(g,grid);
		
	}
	
	for(int i = 0; i < m-1; i++){
		for(int j = i+1; j < m; j++){
			for(int a = 0; a < shifts[i].size(); a++){
				// check if a is valid
				vector<vector<char>> grid(n,vector<char>(n,'.'));
				bool valid = true;
				for(int r = 0; r < n; r++){
					for(int c = 0; c < n; c++){
						if(target[r][c] == '#' and shifts[i][a][r][c] == '#'){
							grid[r][c] = '#';
						}
						if(target[r][c] == '.' and shifts[i][a][r][c] == '#'){
							valid = false;
						}
					}
				}
				if(!valid){
					continue;
				}
				//debug(i,j,a);
				for(int b = 0; b < shifts[j].size(); b++){
					vector<vector<char>> newgrid = grid;
					for(int r = 0; r < n; r++){
						for(int c = 0; c < n; c++){
							if(grid[r][c] == '#' and shifts[j][b][r][c] == '#'){
								valid = false;
							}
							if(grid[r][c] == '.' and shifts[j][b][r][c] == '#'){
								newgrid[r][c] = '#';
							}
						}
					}
					//print(b);
					//printgrid(newgrid);
					//print(valid);

					if(!valid){
						valid = true;
						continue;
					}
					
					// final check
					for(int r = 0; r < n; r++){
						for(int c = 0; c < n; c++){
							if(target[r][c] != newgrid[r][c]){
								valid = false;
							}
						}
					}
					if(valid){
						cout<<i+1<<" "<<j+1;
						return;
					}
				}
			}
		}
	}
	//debuggrid(2);
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);int t = 1;
	// ri(t);
	while(t--)doStuff();
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}
