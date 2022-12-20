#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2000, INF = 1e9;

int n, h[MAXN]; ll numPairs; set<pair<int, double>> canSee[MAXN];

double calcSlope(int i, int j){
    double dy = h[j] - h[i], dx = j - i;
    return dy / dx;
}

void calcPairs(int i){
    double maxSlope = -INF;
    for(int j = i + 1; j < n; j++){
        double curSlope = calcSlope(i, j);
        if(curSlope >= maxSlope){
            canSee[i].insert({j, curSlope});
            maxSlope = max(maxSlope, curSlope);
            numPairs++;
        }
    }
}

void update(int idx, int inc){
    h[idx] += inc, numPairs -= canSee[idx].size();
    canSee[idx].clear();
}

void solve(){
    int idx, inc; cin >> idx >> inc; --idx;
    update(idx, inc), calcPairs(idx);
    for(int j = idx - 1; j >= 0; j--){
        numPairs -= canSee[j].size();
        double curSlope = calcSlope(j, idx);
        auto cur = canSee[j].lower_bound({idx, -INF}), temp = cur;
        bool seePrev = true;
        if(temp != canSee[j].begin()){
            temp--; double tempSlope = temp -> second;
            seePrev = (curSlope < tempSlope);
        } else {
            seePrev = false;
        }
        if(seePrev){
            numPairs += canSee[j].size();
        } else {
            vector<pair<int, double>> rem;
            while(cur != canSee[j].end()){
                double idxSlope = (cur -> second);
                if(idxSlope >= curSlope) break;
                rem.push_back({cur -> first, idxSlope}); cur++;
            }
            for(pair<int, double> x: rem){
                canSee[j].erase(canSee[j].find({x.first, x.second}));
            }
            canSee[j].insert({idx, curSlope}), numPairs += canSee[j].size();
        }
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n; numPairs = 0;
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) calcPairs(i);
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        solve(); cout << numPairs << "\n";
    }
}
