// Problem: Problem 3. Milk Measurement
// Contest: USACO - USACO 2017 December Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=761
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file measurement.in  
// Output: file measurement.out  
// Attempted: 2021-07-31 09:15:36 EST
// ALL TEST CASES PASSED

#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pi;

const int INF = 1e18, MOD = 1e9+7;
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
	ifstream cin("measurement.in");
	ofstream cout("measurement.out");
	int n;
	cin>>n;
	vector<pair<int,pair<string,int>>> info(n);
	
	for(int i = 0; i < n; i++){
		string name, change;
		int day;
		cin>>day>>name>>change;
		int changenum;
		if((int)change.find('-') == -1){
			changenum = stoi(change.substr(1));
		}
		else changenum = stoi(change.substr(1)) * -1;
		
		info[i] = make_pair(day,make_pair(name,changenum));
	}
	
	sort(all(info));
	
	vector<bool> dayschange(101,false);
	
	map<string, int> cows;
	cows["Bessie"] = 7;
	cows["Elsie"] = 7;
	cows["Mildred"] = 7;
	
	string leading = "BessieElsieMildred";
	
	int prevmax = 7;
	int prevcount = 3;
	for(auto i: info){
		cows[i.S.F] += i.S.S;
		string templead = "";
		int maxnum = -1000;
		for(auto j: cows){
			maxnum = max(maxnum,j.S);
		}
		int maxcount =0;
		for(auto j: cows){
			if(j.S == maxnum){
				maxcount++;
				templead += j.F;
			}
		}
		if(prevmax != maxnum && (int)leading.find(templead) == -1){
			dayschange[i.F] = true;
		}
		else if(maxcount != prevcount){
			dayschange[i.F] = true;
		}
		prevmax = maxnum;
		prevcount = maxcount;
		leading = templead;
		
	}
	
	print(count(all(dayschange),true));
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
	

	return 0;
}
