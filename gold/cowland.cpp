// author: envy uwu <3
// problem: Problem 1. Cow Land
// created: 1/25/2022 9:18 PM

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

template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

struct segtree {

    vector<int> seg;
    int _n;

    segtree(int nn) {
        seg.resize(2 * nn, 0LL);
        _n = nn;
    }

    void update(int k, int x) {
        k += _n;
        seg[k] ^= x;
        k /= 2;
        while (k > 0) {
            seg[k] = seg[2 * k] ^ seg[2 * k + 1];
            k /= 2;
        }

    }
    int query(int l, int r) {
        l += _n, r += _n;
        int sum = 0;
        while (l <= r) {
            if (l % 2 == 1) {
                sum ^= seg[l];
                l++;
            }
            if (r % 2 == 0) {
                sum ^= seg[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }

        return sum;
    }

};

const int MAXN = 2e5+5, L = 20;
vector<int> graph[MAXN];
int enter[MAXN], leave[MAXN], up[MAXN][L], val[MAXN];
int timer = 1;
segtree st(MAXN+1);

void dfs(int node, int p){
    enter[node] = timer++;
    up[node][0] = p;
    for(int i: graph[node])
        if(i != p)dfs(i,node);
    leave[node] = timer++;
}

bool anc(int a, int b){
    return enter[b] >= enter[a] && leave[a] >= leave[b];
}

int lca(int a, int b){
    if(anc(a,b))return a;
    for(int k = L-1; k >= 0; k--){
        if(!anc(up[a][k],b))
            a = up[a][k];
    }
    return up[a][0];
}

void solve() {
    int n,q; cin>>n>>q;
    vector<int> deg(n+1);
    for(int i = 1; i <= n; i++){
        cin>>val[i];
    }
    for(int i = 0; i < n-1; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    for(int i = 1; i <= n; i++){
        if(deg[i] == 1){
            dfs(i,i);
            break;
        }
    }

    for(int k = 1; k < L; k++){
        for(int i = 1; i <= n; i++){
            up[i][k] = up[up[i][k-1]][k-1];
        }
    }

    for(int i = 1; i <= n; i++){
        st.update(enter[i],val[i]);
        st.update(leave[i],val[i]);
    }

    while(q--){
        int t,i,j; cin>>t>>i>>j;
        if(t == 1){
            st.update(enter[i],val[i]);
            st.update(leave[i],val[i]);
            val[i] = j;
            st.update(enter[i],val[i]);
            st.update(leave[i],val[i]);
        }
        else{
            cout<<((st.query(1,enter[i])^st.query(1,enter[j]))^val[lca(i,j)])<<"\n";
        }
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    freopen("cowland.in","r",stdin);
    freopen("cowland.out","w",stdout);
    while (t--) {
        solve();
    }

}
