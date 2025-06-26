#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
#define IN "A.in"
#define OUT "A.out"
 
 
const ll MOD = (ll) 1e9 + 7;
vector <ll> f(1000001, 1);
 
ll powMod(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
 
    while (b) {
        if (b % 2 == 1) {
            res *= a;
            res %= m;
        }
 
        a *= a;
        a %= m;
        b /= 2;
    }
 
    return res;
}
 
ll inverse(ll a, ll m) {
    return powMod(a, m-2, m);
}
 
void solve() {
    string s; cin >> s;
 
    map <char, ll> freq;
 
    for (auto &ch : s) {
        freq[ch]++;
    }

    ll mau = 1;
    for (auto &x : freq) {
        mau = mau % MOD * inverse(f[x.second] % MOD, MOD) % MOD;
    }
 
    cout << f[s.size()] % MOD * mau % MOD << endl;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }
 
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    for (ll i = 1; i <= 1000001; i++) {
        f[i] = f[i-1] * i;
        f[i] %= MOD;
    }
 
    // ll t; cin >> t;
    // while (t--)
        solve();
}
