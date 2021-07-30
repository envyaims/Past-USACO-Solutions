// Problem: Problem 3. Guess the Animal
// Contest: USACO - USACO 2019 January Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=893
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file guess.in
// Output: file guess.out
// Attempted: Fri, 7/23/2021 4:25:23 PM

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pi;

const int INF = 2e5+10, MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<endl
#define print(x) cout<<x<<endl
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())


void solve(){
	ifstream cin("guess.in");
	ofstream cout("guess.out");
	int n;
	cin>>n;
	map<string,vector<string>> animals;
	for(int i = 0; i < n; i++){
		string animal;
		int n2;
		vector<string> traits;
		cin>>animal>>n2;
		for(int j = 0; j < n2; j++){
			string b;
			cin>>b;
			traits.pb(b);
		}
		animals.insert({animal,traits});
	}
	int ans = 0;
	for(auto i: animals){
		for(auto j:animals){
			if(i.F != j.F){
				int similar = 0;
				for(string k: i.S){
					for(string p: j.S){
						if(k == p)similar++;
					}
				}
				ans = max(ans,similar);
				
				
			}
		}
	}
	print(ans+1);
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    

    return 0;
}
