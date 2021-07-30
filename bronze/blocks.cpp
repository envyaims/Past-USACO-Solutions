// Problem: Problem 2. Block Game
// Contest: USACO - USACO 2016 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=664
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file blocks.in  
// Output: file blocks.out  
// Attempted: 2021-07-30 09:08:46 EST
// all test cases passed

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pi;

const ll INF = 1e18;
const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<endl
#define print(x) cout<<x<<endl
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())


void doStuff(){
	ifstream cin("blocks.in");
	ofstream cout("blocks.out");
	int n;
	cin>>n;
	vector<int> letters(26,0);
	
	for(int i = 0; i < n; i++){
		string a,b; cin>>a>>b;
		set<char> removedupes;
		for(char j:a){
			removedupes.insert(j);
		}
		for(char j: removedupes){
			int cnt = max(count(all(a),j), count(all(b),j));
			letters[int(j) - 97] += cnt;
		}
		for(char j: b){
			if(count(all(a),j) == 0){
				letters[int(j) - 97] ++;
			}
		}
	}
	for(int i: letters){
		print(i);
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
