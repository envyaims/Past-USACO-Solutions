#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
char grid[50][50];
int ans = 0;

// dir == 0 is down, dir == 1 is right
void recurse(int r, int c, int know, bool dir, bool is_not_first = false){
        // r = current row, c = current col, know = how many turns so far, dir = direction, 
    if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == 'H')return; // check for out of bounds and if current square is blocked
    if(r == n-1 && c == n-1){
        ans++; // if reached end, increase answer
        return;
    }
        // bessie turns
    if(know < k && is_not_first){ // if we can turn and it is not the first square
        if(dir){ // if we are going down...
            recurse(r,c+1,know+1,!dir, 1); // turn right, and increase current k count
        }
        else{
            recurse(r+1,c,know+1,!dir, 1); // turn down, and increase current k count
        }
    }

         // keep going the current direction
    if(dir){ 
            recurse(r+1,c,know,dir, 1);
        }
        else{
            recurse(r,c+1,know,dir, 1);
        }
}

void test_case(){
    ans = 0;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>grid[i][j];
        }
    }
    
    recurse(0,0,0,0); // bessie is going down initially
    recurse(0,0,0,1); // bessie is going to the right initially
    printf("%lld\n",ans);
    
}

main(){
    int t; cin>>t;
    while(t--){
        test_case();
    }
}
