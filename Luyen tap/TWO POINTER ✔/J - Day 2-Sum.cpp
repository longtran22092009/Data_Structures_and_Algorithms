#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    ll ans = 0;
    for (int k = 0; k < n; k++) {
        ll sum1 = 0, sum2 = 0;
        int l = k;

        for (int r = k+1; r < n; r++) {
            sum2 += a[r];
            while (l >= 0 && sum1 + a[l] <= sum2) sum1 += a[l--];

            if (sum1 == sum2) {
                // cout << k << " " << l << " " << r << endl;
                ans = max(ans, 1ll * (r-l));
            }
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