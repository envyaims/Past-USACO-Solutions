// Problem: Problem 2. Why Did the Cow Cross the Road II
// Contest: USACO - USACO 2017 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=712
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file circlecross.in  
// Output: file circlecross.out  
// Attempted: 2021-07-30 11:35:28 EST
// all test cases passed lol

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
	ifstream cin("circlecross.in");
	ofstream cout("circlecross.out");
	string s;
	cin>>s;
	
	set<pair<char,char>> ans;
	for(int i = 0; i < 52; i++){
		int pos = s.find(s[i], i+1);
		if(pos != -1){
			string sub = s.substr(i+1,pos-i-1);
			for(char j: sub){
				if(count(all(sub),j) == 1){
					ans.insert(mp(min(s[i],j),max(s[i],j)));
				}
			}
		}
	}
	print(ans.size());
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
