// Problem: Problem 1. Angry Cows
// Contest: USACO - USACO 2016 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=594
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file angry.in  
// Output: file angry.out  
// Attempted: 2021-08-16 11:25:10 EST

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
int n,k;
vector<int> nums;

bool check(int x){
	int cows = k;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(cows == 0){
			break;
		}
		int blast = nums[i] + x + x;
		cows--;
		while(i < n){
			if(nums[i] <= blast){
				cnt++;
				i++;
			}
			else break;
		}
		i--;
	}
	debug(cows);
	debug(cnt);
	return cnt == n;
	
}


void doStuff(){
	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);
	ri(n,k);
	nums.resize(n);
	for(int i = 0; i < n; i++){
		ri(nums[i]);
	}
	sort(all(nums));
	int start = 0, end = 1e5;
	while(start < end-1){
		int mid = start + (end-start)/2;
		if(check(mid)){
			end = mid;
		}
		else start = mid;
	}
	print(end);
	
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
