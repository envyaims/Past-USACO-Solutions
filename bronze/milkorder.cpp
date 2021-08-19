// Problem: Problem 2. Milking Order
// Contest: USACO - USACO 2018 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=832
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file milkorder.in  
// Output: file milkorder.out  
// Attempted: 2021-08-18 20:23:31 EST

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
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define bpop(x) __builtin_popcount(x)
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};

void doStuff(){
	freopen("milkorder.in","r",stdin);
	freopen("milkorder.out","w",stdout);
	int n,m,k; ri(n,m,k);
	vector<pair<int,int>> social(m);
	for(int i = 0; i < m; i++){
		int a; ri(a);
		social[i] = mp(a,-1);
	}
	vector<int> pos(n+1,0);
	for(int i = 0; i < k; i++){
		int a,b; ri(a,b);
		pos[b] = a;
		if(a == 1){
			print(b);
		}
		for(int j = 0; j < m; j++){
			if(social[j].F == a){
				social[j].S = b;
				break;
			}
		}
	}
	vector<bool> met(101,false);
	for(int i = 1; i <= n; i++){
		if(pos[i] != 0){
			bool found = false;
			for(int j = 0; j < m; j++){
				if(social[j].F == pos[i]){
					found = true;
					met[social[j].F] = true;
					for(int p = j-1; p >= 0; p--){
						if(social[p].S == -1 && !met[social[p].F]){
							for(int l = i-1; l >= 1; l--){
								if(pos[l] == 0){
									pos[l] = social[p].F;
									met[social[p].F] = true;
									social[p].S = l;
									break;
								}
							}
						}
					}
					break;
				}
			}
			
		}
	}
	

	if(find(all(social),mp(1,-1)) == social.end()){
		// if 1 is not in the order, then all the other cows should be pushed back 
		// as futher as possble
		social.pb(mp(101,n+1));
		for(int i = m-1; i >= 0; i--){
		if(social[i].S == -1){
			for(int j = social[i+1].S-1; j>= 1; j--){
				if(pos[j] == 0){
					pos[j] = social[i].F;
					social[i].S = j;
					break;
					}
				}
			}
		}
	}
	else{
		// if 1 is in the order, then 1 should show up as early as possible
		for(int i = 0; i < m; i++){
			if(social[i].S != -1){
				for(int j = i+1; j < m; j++){
					if(social[j].S == -1){
						for(int l = social[i].S+1 ; l <= n; l++){
							if(pos[l] == 0){
								pos[l] = social[j].F;
								social[j].S = l;
								break;
							}
						}
					}
				}
				break;
			}
		}
	}
	
	// if the cows in the order and already placed in pos array
	bool inorder = false;
	bool hasone = false;
	for(int i = 0; i < m; i++){
		if(social[i].S != -1){
			inorder = true;
			break;
		}
		if(social[i].F == 1){
			hasone = true;
		}
	}
	// if not and one is there we can order the cows as early as possible
	
	// if one is not there it doesnt matter because the cows has to take the
	// latest positions, and the code which prints the output searched for the
	// first empty slot.
	
	if(hasone && !inorder){
		for(int i = 0; i < m; i++){
			for(int j = 1; j <= n; j++){
				if(pos[j] == 0){
					pos[j] = social[i].F;
					break;
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(pos[i] == 1){
			print(i);
			return;
		}
	}
	for(int i = 1; i <= n; i++){
		if(pos[i] == 0){
			print(i);
			return;
		}
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

// you should actually read the stuff at the bottom and not submit the same wrong code

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* maybe just stop being dumb lol
*/
