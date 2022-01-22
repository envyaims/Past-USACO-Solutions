#include <bits/stdc++.h>
using namespace std;
#define int long long

main(){
    int n; cin>>n;
    vector<int> wish(n), stall(n);
    for(int& i: wish)cin>>i;
    for(int& i: stall)cin>>i;
    vector<int> diff(n);
    for(int i = 0; i < n; i++){
        diff[i] = wish[i] - stall[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){ // looping to find the start of a segment
        while(diff[i] != 0){ // while found start is not already ok
            // the start of the segment also determines if we are finding an all negative or all positive segment
            int atleast = diff[i]; // we must increase or decrease this much temperature. 
            int nxt = i; // where the segment shall end
            for(int j = i+1; j < n; j++){
                if(diff[j] > 0 && atleast > 0){ // if we are finding a positive segment and this element is also positive
                    atleast = min(atleast,diff[j]); 
                    nxt = j; 
                }
                else if(diff[j] < 0 && atleast < 0){ // if we are finding a negative segment and this element is also negative.
                    atleast = max(atleast,diff[j]); // we take the maxinum since we want to get it closest to 0.
                    nxt = j;
                }
                else break; // the segment has been interrupted, break out.
            }
            for(int j = i; j <= nxt; j++){
                diff[j] -= atleast; // decrease every element in the segment
            }
            ans += abs(atleast);
        }
    }
    
    printf("%lld",ans);
}
