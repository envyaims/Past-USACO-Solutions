#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll modpow(ll a, ll b, ll m){
	ll res = 1;
	while(b){
		if(b & 1) res = (res * a) % m;
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

vector<ll> facts = {1,1};
vector<ll> inverse = {1, 1};

ll ncr(ll n, ll k){
   return facts[n] % MOD * inverse[k] % MOD * inverse[n - k] % MOD;
}

void pre(){
	int m = 1e6;
	inverse.resize(m+1);
	for(ll i = 2; i <= m; i++){
		facts.push_back(facts.back() * i % MOD);
		inverse[i] = modpow(facts.back(), MOD-2, MOD);
	}
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	pre();
	int n; cin >> n;
	vector<ll> a(n);
	for(ll& i: a) cin >> i, i /= 2;
	ll ans = 1;
	for(int i = 0; i < n - 1; i++){
		ans = ans * (a[i] < a[i+1] ? ncr(a[i+1]-1, a[i]-1) : ncr(a[i], a[i+1])) % MOD;
	}
	cout << ans << endl;
	
}
