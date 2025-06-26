#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


// Hoán vị lạc chỗ (Derangement)
// D(n) = (n-1)(D(n-1) + D(n-2))

const ll MOD = (ll) 1e9 + 7;
vector <ll> d(1000001);

void solve() {
    ll n; cin >> n;

    d[1] = 0;
    d[2] = 1;
    for (ll i = 3; i <= n; i++) {
        d[i] = ((i-1) % MOD) * (d[i-1] + d[i-2] % MOD) % MOD;
    }

    cout << d[n] << endl;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    // ll t; cin >> t;
    // while (t--)
    solve();
}
