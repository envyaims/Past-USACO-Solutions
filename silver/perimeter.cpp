// Problem: Problem 2. Icy Perimeter
// Contest: USACO - USACO 2019 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=895
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file perimeter.in  
// Output: file perimeter.out  
// Attempted: 2021-08-05 09:49:28 EST

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
const int MOD = 1e9+7, MN = 1e5 + 5;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())

int n;
int area = 0;
int peri = 0;
char grid[1001][1001];
bool visited[1001][1001];

void floodfill(int row, int col){
	if(row < 0 || row >= n || col < 0 || col >= n || grid[row][col] == '.'){
		peri++;
		return;
	}
	if(visited[row][col])return;
	
	visited[row][col] = true;
	
	if(grid[row][col] == '#')area++;
	
	floodfill(row,col+1);
	floodfill(row,col-1);
	floodfill(row+1,col);
	floodfill(row-1,col);
}

void doStuff(){
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
	ri(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			rc(grid[i][j]);
		}
	}
	
	int outarea = 0;
	int outperi = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j] && grid[i][j] == '#'){
				floodfill(i,j);
				if(area == outarea){
					outperi = min(outperi,peri);
				}
				else if(area > outarea){
					outarea = area;
					outperi = peri;
				}
				peri = 0;
				area = 0;
			}
		}
	}
	cout<<outarea<<" "<<outperi;
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    
    return 0;
}

// you should actually read the stuff at the bottom and not submit the same wrong code

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* most importantly stop being an dumb
*/
