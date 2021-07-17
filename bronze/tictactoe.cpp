// Problem: Problem 1. Team Tic Tac Toe
// Contest: USACO - USACO 2018 US Open Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=831
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// 5/10 test cases. 7/16/2021

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX
#define all(x) x.begin(), x.end() // for vectors, etc
#define All(x,l) x, x+l // for standard arrays, l = length
#define pb(x) push_back(x)
#define debug(x) fout<<#x<<" = "<<x<<endl
#define print(x) fout<<x<<endl
#define mp(x,y) make_pair(x,y)
#define cpy(x,y) copy(begin(x),end(x),begin(y)) // copy standard arrays x -> y

template<typename T>
vector<string> split(T str, char sep){
	vector<string> output;
	size_t start = 0, end = 0;
	while((end = str.find(sep,start)) != string::npos){
		if(end != start)output.pb(str.substr(start,end-start));
		start = end+1;
	}
	
	if(end != start)output.pb(str.substr(start));
	return output;
	
}


void solve(){
	ifstream fin("tttt.in");
	ofstream fout("tttt.out");
	char board[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			fin>>board[i][j];
		}
	}
	
	int singles = 0;
	int doubles = 0;
	
	// straight wins
	for(int i = 0; i < 3; i++){
		set<char> winners;
		for(int j = 0; j < 3; j++){
			winners.insert(board[i][j]);
		}
		if(winners.size() == 1)singles++;
		if(winners.size() == 2)doubles++;
	}
	
	// horizontal
	for(int i = 0; i < 3; i++){
		set<char> winners;
		for(int j = 0; j < 3; j++){
			winners.insert(board[j][i]);
		}
		if(winners.size() == 1)singles++;
		if(winners.size() == 2)doubles++;
	}
	
	// diagonals
	
	set<char> winners = {board[0][0],board[1][1],board[2][2]};
	if(winners.size() == 1)singles++;
	if(winners.size() == 2)doubles++;
	
	set<char> winners2 = {board[0][2],board[1][1], board[2][0]};
	if(winners2.size() == 1)singles++;
	if(winners2.size() == 2)doubles++;
	
	fout<<singles<<endl;
	fout<<doubles<<endl;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
