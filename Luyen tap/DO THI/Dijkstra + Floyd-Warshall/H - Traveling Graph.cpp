#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 20, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

int n, m, totalWeight = 0;
vector <int> deg(mxN, 0);
vector <vector <int>> d(mxN, vector <int>(mxN, INF));

void solve() {
    cin >> n >> m;

    if (m == 0) {
        cout << "0\n";
        return;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        deg[u]++;
        deg[v]++;
        totalWeight += w; // Base cost (all edges)
        d[u][v] = d[v][u] = min(d[u][v], w);
    }

    // for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (d[u][k] == INF || d[k][v] == INF) continue;
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }

    // Unreachable from 1 to other
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > 0 && d[1][i] == INF) {
            cout << "-1\n";
            return;
        }
    }

    // Eulerian Circuit => all vertic will have even degree
    vector <int> odd;
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 != 0) odd.push_back(i);
    }
    // All vertics have even degree
    int k = odd.size();
    if (k == 0) {
        cout << totalWeight << endl;
        return;
    }

    // Pair up the odd-degree vertics
    vector <int> dp((1 << k), INF);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << k); mask++) {
        if (dp[mask] == INF) continue; // Not valid

        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) continue; // Already use this vertic
            for (int j = i+1; j < k; j++) {
                if (mask & (1 << j)) continue;
                // Turn bit i and j
                int new_mask = mask | (1 << i) | (1 << j);
                // Minimum if pair up i, j
                dp[new_mask] = min(dp[new_mask], dp[mask] + d[odd[i]][odd[j]]);
            }
        }
    }

    cout << totalWeight + dp[(1 << k) - 1] << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    cerr << "Time: " << clock() - start << "ms\n";
}
