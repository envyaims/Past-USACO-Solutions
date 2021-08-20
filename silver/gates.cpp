// Problem: Problem 3. Build Gates
// Contest: USACO - USACO 2016 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=596
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file gates.in  
// Output: file gates.out  
// Attempted: 2021-08-20 08:03:09 EST

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

vector<vector<bool>> fence(4004,vector<bool>(4004,false));
vector<vector<bool>> visited(4004,vector<bool>(4004,false));
int n;
int maxx = 2001, maxy = 2001, minx = 2001, miny = 2001;

void floodfill(int r, int c){
	if(r > maxx || r < minx || c > maxy || c < miny || fence[r][c] || visited[r][c]){
		return;
	}
	visited[r][c] = true;
	
	for(int i = 0; i < 4; i++){
		floodfill(r + dx[i],c + dy[i]);
	}
}

void doStuff(){
	freopen("gates.in","r",stdin);
	freopen("gates.out","w",stdout);
	ri(n);
	// start at 1000;
	int posx = 2001;
	int posy = 2001;
	fence[2001][2001] = true;
	for(int i = 0; i < n; i++){
		char a; rc(a);
		if(a == 'N'){
			fence[posx][posy+1] = true;
			fence[posx][posy+2] = true;
			posy += 2;
		}
		else if(a == 'S'){
			fence[posx][posy-1] = true;
			fence[posx][posy-2] = true;
			posy -= 2;
		}
		else if(a == 'W'){
			fence[posx-1][posy] = true;
			fence[posx-2][posy] = true;
			posx-= 2;
		}
		else if(a == 'E'){
			fence[posx+1][posy] = true;
			fence[posx+2][posy] = true;
			posx+= 2;
		}
		
		maxx = max(maxx,posx);
		minx = min(minx,posx);
		miny = min(miny,posy);
		maxy = max(maxy,posy);
	}
	minx--; maxx++; miny--; maxy++;
	debug(maxx);
	debug(maxy);
	debug(miny);
	debug(minx);
	
	int ans = 0;
	for(int i = minx; i <= maxx; i++){
		for(int j = miny; j <= maxy; j++){
			if(!visited[i][j] && !fence[i][j]){
				ans++;
				floodfill(i,j);
			}
		}
	}
	print(ans-1);
	
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

// you should actually read the stuff at the bottom and not submit the same wrong code

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* maybe just stop being dumb lol
*/
