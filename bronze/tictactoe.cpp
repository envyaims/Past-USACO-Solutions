// Problem: Problem 1. Team Tic Tac Toe
// Contest: USACO - USACO 2018 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=831
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file tttt.in  
// Output: file tttt.out  
// Attempted: 2021-07-30 09:25:36 EST
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
	ifstream cin("tttt.in");
	ofstream cout("tttt.out");
	vector<string> board(3);
	for(int i = 0; i < 3; i++){
		string s;cin>>s;
		board[i] = s;
	}	
	
	set<set<char>> singles,doubles;
	set<char> wins;
	
	// horizontally
	for(int i = 0; i < 3; i++){
		for(char j: board[i]){
			wins.insert(j);
		}
		if(wins.size() == 1)singles.insert(wins);
		else if(wins.size() == 2)doubles.insert(wins);
		wins.clear();
	}
	
	// vertically
	for(int i = 0; i < 3; i++){
		set<char> wins;
		for(int j = 0; j < 3; j++){
			wins.insert(board[j][i]);
		}
		if(wins.size() == 1)singles.insert(wins);
		else if(wins.size() == 2)doubles.insert(wins);
		wins.clear();
	}
	
	// diagonally
	
	for(int i = 0; i < 3; i++){
		wins.insert(board[i][i]);
	}
	if(wins.size() == 1)singles.insert(wins);
	else if(wins.size() == 2)doubles.insert(wins);
	wins.clear();
	
	wins.insert(board[2][0]);
	wins.insert(board[1][1]);
	wins.insert(board[0][2]);
	if(wins.size() == 1)singles.insert(wins);
	else if(wins.size() == 2)doubles.insert(wins);
	wins.clear();
	
	print(singles.size());
	print(doubles.size());

	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    

    return 0;
}
