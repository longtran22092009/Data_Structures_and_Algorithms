#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "diamond.in"
#define OUT "diamond.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, k; cin >> n >> k;

    vector <int> a(n);
    for (auto &x : a) cin >> x;
    sort(begin(a), end(a));

    vector <int> len(n);
    for (ll l = 0; l < n; l++) {
        ll r = l;
        while (r < n && a[r] - a[l] <= k) ++r;
        len[l] = r-l;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + len[i]; j < n; j++) {
            ans = max(ans, 1ll* len[i] + len[j]);
        }
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