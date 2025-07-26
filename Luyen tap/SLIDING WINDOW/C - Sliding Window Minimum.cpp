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

    vector <ll> v(n);
    v[0] = x;
    for (int i = 1; i < n; i++) {
        v[i] = (a % c * v[i-1] % c + b) % c;
    }

    deque <int> q; // Store the index
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        // Out of the current window range
        if (!q.empty() && q.front() <= i-k) q.pop_front();
        // Keep the deque increasing from back to front
        while (!q.empty() && v[q.back()] >= v[i]) q.pop_back();
        // Add the next element to the current window range
        q.push_back(i);
        if (i >= k-1) ans ^= v[q.front()];
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