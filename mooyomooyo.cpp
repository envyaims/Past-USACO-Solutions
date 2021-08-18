// Problem: Problem 3. Mooyo Mooyo
// Contest: USACO - USACO 2018 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=860
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file mooyomooyo.in  
// Output: file mooyomooyo.out  
// Attempted: 2021-08-18 15:10:45 EST
// AC WOOHOO FIRST TRY

#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << #__VA_ARGS__ << ":", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif


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
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define bpop(x) __builtin_popcount(x)
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};

char grid[101][10];
int n,k;
bool endloop = false;

void floodfill(int r, int c, char color, vector<vector<bool>>& visited, int& counter){
	if(r >= n || r < 0 || c >= 10 || c < 0){
		return;
	}
	if(grid[r][c] != color || visited[r][c])return;
	counter++;
	visited[r][c] = true;
	
	for(int i = 0; i < 4; i++){
		int row = dx[i] + r;
		int col = dy[i] + c;
		floodfill(row,col,grid[r][c],visited,counter);
	}
}

void deletethese(int r, int c, char color, vector<vector<bool>>& visited){
	if(r >= n || r < 0 || c >= 10 || c < 0){
		return;
	}
	if(grid[r][c] != color || visited[r][c])return;
	visited[r][c] = true;
	grid[r][c] = '0';
	
	for(int i = 0; i < 4; i++){
		int row = dx[i] + r;
		int col = dy[i] + c;
		deletethese(row,col,color,visited);
	}
}

void gravity(){
	for(int i = n-1; i >= 1; i--){
		for(int j = 0; j < 10; j++){
			if(grid[i][j] == '0'){
				int stacked = 0;
				for(int r = i-1; r >= 0; r--){
					if(grid[r][j] != '0'){
						grid[i-stacked][j] = grid[r][j];
						grid[r][j] = '0';
						stacked++;
					}
				}
			}
		}
	}
}

void doStuff(){
	freopen("mooyomooyo.in","r",stdin);
	freopen("mooyomooyo.out","w",stdout);
	ri(n,k);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			rc(grid[i][j]);
		}
	}
	
	while(!endloop){
		endloop = true;
		vector<vector<bool>> visited(n,vector<bool>(10,false));
		for(int i = n-1; i >= 0; i--){
			for(int j = 0; j < 10; j++){
				if(grid[i][j] != '0' && !visited[i][j]){
					int counter = 0;
					floodfill(i,j,grid[i][j],visited,counter);
					if(counter >= k){
						endloop = false;
						vector<vector<bool>> deletethis(n,vector<bool>(10,false));
						deletethese(i,j,grid[i][j],deletethis);
					}
					
					
				}
			}
		}
		gravity();
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			cout<<grid[i][j];
		}
		cout<<endl;
	}
	
	
}

int main(){
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

