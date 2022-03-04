#include <bits/stdc++.h>

#ifndef LOCAL
#define debug(...) 0
#else

#include "C:\programmingfunnyxd\debug.cpp"

#endif

using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
const int N = 1e5+5;

struct DSU {
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n);
        sz.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int get(int x) {
        if (p[x] != x) {
            p[x] = get(p[x]);
        }
        return p[x];
    }

    bool unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (sz[a] < sz[b])swap(a, b);
        if (a != b) {
            p[b] = a;
            sz[a] += sz[b];
        }
        return a != b;
    }

    bool sameset(int a, int b) { return get(a) == get(b); }

    int getsize(int a) { return sz[get(a)]; }
};

int dist(pair<int,int> a, pair<int,int> b){
    int dx = a.F - b.F, dy = a.S - b.S;
    return dx*dx+dy*dy;
}

void solve() {
    int n; cin>>n;
    vector<pair<int,int>> coords(n);
    for(int i = 0; i < n; i++){
        int u,v; cin>>u>>v;
        coords[i] = {u,v};
    }
    sort(all(coords));
    DSU dsu(n);
    vector<array<int,3>> edges;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= i+20 && j < n; j++){
            edges.push_back({dist(coords[i],coords[j]),i,j});
        }
    }
    sort(all(edges));
    int ans = 0;
    for(auto i: edges){
        if(dsu.unite(i[1],i[2])){
            ans += i[0];
        }

    }
    cout<<ans<<endl;


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }

}
