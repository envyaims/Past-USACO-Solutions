#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 4, sides = 6;

signed main() {
	int n; cin>>n;
	vector<string> cubes(m);
	for(int i = 0; i < m; i++){
		cin>>cubes[i];
	}
	set<string> possible;
	for(char a: cubes[0]){
		for(char b: cubes[1]){
			for(char c: cubes[2]){
				for(char d: cubes[3]){
					string s;
					for(char e: {a,b,c,d})s.push_back(e);
					sort(s.begin(),s.end());
					possible.insert(s);
				}
			}
		}
	}
	while(n--){
		bool found = false;
		string cur; cin>>cur;
		sort(cur.begin(),cur.end());
		int x = cur.length();
		for(string s: possible){
			int idx = -1;
			bool ok = true;
			for(char c: cur){
				if(s.find(c,idx+1) != string::npos){
					idx = s.find(c,idx+1);
				}
				else{
					ok = false;
					break;
				}
			}
			if(ok)found = true;
		}
		puts(found ? "YES" : "NO");
	}
}
