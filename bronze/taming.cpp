// Problem: Problem 3. Taming the Herd
// Contest: USACO - USACO 2018 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=809
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// ALL TEST CASES PASSED 7/30/2021

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX
#define all(x) x.begin(), x.end() // for vectors, etc
#define All(x,l) x, x+l // for standard arrays, l = length
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<endl
#define print(x) cout<<x<<endl
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))


void solve(){
	ifstream cin("taming.in");
	ofstream cout("taming.out");
	int n;
	cin>>n;
	vector<int> log(n);
	for(int i = 0 ; i < n; i++){
		cin>>log[i];
	}	
	
	int prevnum;
	int streak = false;
	if(log[0] != -1 && log[0] != 0){
		print(-1);
		return;
	}
	log[0] = 0;
	for(int i = n-1; i > 0; i--){
		if(log[i] > 0 && !streak){
			streak = true;
			prevnum = log[i];
			continue;
		}
		

		if(streak){
			if(log[i] == -1 || log[i] == prevnum-1){
				log[i] = prevnum-1;
				prevnum = log[i];
			}
			else if(log[i] != prevnum-1){
				print(-1);
				return;
			}
		}
		if(log[i] == 0){
			streak = false;
		}
		
	}
	
	int maxans = 0;
	int minans = 0;
	for(int i = 0; i < n; i++){
		if(log[i] == 0){
			minans++;
			maxans++;
		}
		if(log[i] == -1){
			maxans++;
		}
	}
	
	cout<<minans<<" "<<maxans;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    

    return 0;
}
