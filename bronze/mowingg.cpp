// Problem: Problem 3. Mowing the Field
// Contest: USACO - USACO 2016 January Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=593
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file mowing.in  
// Output: file mowing.out  
// Attempted: 2021-07-30 10:21:51 EST

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

int visited[10000][10000];
void doStuff(){
	ifstream cin("mowing.in");
	ofstream cout("mowing.out");
	
	int n;
	cin>>n;
	int ans = 10000;
	
	int xpos = 5000;
	int ypos = 5000;
	int t = 1;
	visited[5000][5000] = 1;
	
	for(int i = 0; i < n; i++){
		char s;
		int dist;
		cin>>s>>dist;
		
		for(int j = 0; j < dist; j++){
			t++;
			if(s == 'N'){
				ypos++;
			}
			else if(s == 'S'){
				ypos--;
			}
			else if(s == 'W'){
				xpos--;
			}
			else xpos++;
			
			if(visited[xpos][ypos] == 0){
				visited[xpos][ypos] = t;
			}
			else{
				ans = min(ans,t - visited[xpos][ypos]);
				visited[xpos][ypos] = t;
			}
		}
	}
	
	if(ans == 10000)cout<<-1<<endl;
	else cout<<ans<<endl;
	
	
	
}

int main(){
	doStuff();
    

    return 0;
}
