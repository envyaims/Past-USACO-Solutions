// Problem: Problem 1. Year of the Cow
// Contest: USACO - USACO 2021 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=1107
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// ALL TEST CASES PASSED 7/17/2021 

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
#define cpy(x,y) copy(begin(x),end(x),begin(y)) // copy standard arrays x -> y



void solve(){
	vector<string> zodiacs = {
	"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", 
	"Dog", "Pig", "Rat"};
	
	map<string,pair<string,int>> members;
	members.insert({"Bessie",mp("Ox",0)});
	int n;
	cin>>n;
	string s;
	for(int i = 0; i < n; i++){
		string person1, nextprev, zodiac, person2;
		cin>>person1>>s>>s>>nextprev>>zodiac>>s>>s>>person2;
		string zod2 = members[person2].first;
		int year2 = members[person2].second;
		auto zodindex2 = find(all(zodiacs),zod2) - zodiacs.begin();
		auto zodindex = find(all(zodiacs),zodiac)- zodiacs.begin();
		int yeardif = abs(zodindex-zodindex2);
		
		if(nextprev == "next"){
			if(zodindex <= zodindex2){
				yeardif = 12 - yeardif;
			}
			
			members.insert({person1,mp(zodiac,year2+yeardif)});
			
		}
		else{
			if(zodindex >= zodindex2) yeardif = 12-yeardif;
			members.insert({person1,mp(zodiac,year2-yeardif)});
		}
		
	}
	
	cout<< abs(members["Elsie"].second - members["Bessie"].second) <<endl;
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}
