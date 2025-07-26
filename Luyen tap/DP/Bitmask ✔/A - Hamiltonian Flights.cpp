#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

void solve() {
    int n, m; cin >> n >> m;

    vector <vector <int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u-1].push_back(v-1);
    }

    vector <vector <int>> dp(1 << n, vector <int> (n, 0));
    dp[1][0] = 1; // Tu 1 den 1

    for (int mask = 1; mask < (1 << n); mask++) {
        if (!(mask & 1)) continue;
        if (mask & (1 << (n-1)) && mask != (1 << n) - 1) continue;

        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (auto &v : adj[u]) {
                if (mask & (1 << v)) continue;
                dp[mask | (1 << v)][v] = (dp[mask | (1 << v)][v] + dp[mask][u]) % MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1][n-1];
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}
