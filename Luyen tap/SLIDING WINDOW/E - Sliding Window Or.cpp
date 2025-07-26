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

    vector <ll> v(n, x);
    for (int i = 1; i < n; i++) {
        v[i] = (a * v[i-1] + b) % c;
    }
    
    vector <ll> pre(n), suf(n);
    pre[0] = suf[n-1] = x;
    for (int i = 1; i < n; i++) pre[i] = ((i % k == 0)? v[i] : pre[i-1] | v[i]); // Prefix
    for (int i = n-2; i >= 0; i--) suf[i] = ((i % k == k-1)? v[i] : suf[i+1] | v[i]); // Suffix

    ll ans = 0;
    // Start from the last index of the first window
    for (int i = k-1; i < n; i++) { 
        if (i % k == k-1) ans ^= pre[i]; // In a block
        else ans ^= pre[i] | suf[i-k+1]; // Intersection of two block
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