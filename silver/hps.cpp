// Problem: Problem 2. Hoof, Paper, Scissors
// Contest: USACO - USACO 2017 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=691
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file hps.in  
// Output: file hps.out  
// Attempted: 2021-08-01 09:35:46 EST
// AC

#include <bits/stdc++.h>
using namespace std;

inline namespace fastio {
	const int BSZ = 1<<15; 
	char ibuf[BSZ]; int ipos, ilen;
	char nc() { // next char
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
	template<class str>void rs(str& x) { // read str
		char ch; while (isspace(ch = nc()));
		do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);
	}
	template<class T> void rc(T& x){
		x = nc();
		while(isspace(x)){
			x = nc();
		}
	}
}

typedef long long ll;
const int INF = 1e18, MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())


void doStuff(){
	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);

	int n;ri(n);
	vector<int> hoof(n+1,0);
	vector<int> paper(n+1,0);
	vector<int> scissors(n+1,0);
	for(int i = 1; i <= n; i++){
		char a; rc(a);
		hoof[i] = hoof[i-1];
		paper[i] = paper[i-1];
		scissors[i] = scissors[i-1];
		
		if(a == 'P')paper[i]++;
		else if(a == 'H')hoof[i]++;
		else scissors[i]++;
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans,hoof[i] + paper[n] - paper[i]);
		ans = max(ans,hoof[i] + scissors[n] - scissors[i]);
		ans = max(ans,paper[i] + hoof[n] - hoof[i]);
		ans = max(ans,paper[i] + scissors[n] - scissors[i]);
		ans = max(ans,scissors[i] + hoof[n] - hoof[i]);
		ans = max(ans,scissors[i] + paper[n] - paper[i]);
	}
	
	print(ans);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
