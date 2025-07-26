#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    // xi = (a * x(i-1) + b) mod c
    ll n, k; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;

    vector <ll> v(n), pre(n);
    v[0] = pre[0] = x;
    // x = a^b^c, y = b^c^d => y = x^a^d (Hoán vị của phép toán XOR)
    for (int i = 1; i < n; i++) {
        v[i] = (a % c * v[i-1] % c + b) % c;
        pre[i] = pre[i-1] ^ v[i];
    }
    
    ll ans = 0;
    for (int i = 0; i <= n-k; i++) {
        ll curr_xor = pre[i+k-1];
        if (i > 0) curr_xor ^= pre[i-1];
        ans ^= curr_xor;
        // cerr << curr_xor << endl;
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    // ll t; cin >> t;
    // while (t--)
    solve();
}