#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

int n;
vector <vector <int>> cost, dp;

void solve() {
    // Ex: Traveling Salesman Problem (TSP)
    cin >> n;
    cost.assign(n, vector<int>(n));
    for (auto& row : cost)
        for (auto& x : row) cin >> x;

    dp.assign(1 << n, vector<int>(n, INF));
    dp[1][0] = 0; // bắt đầu từ thành phố 0

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int new_mask = mask | (1 << v);
                dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + cost[u][v]);
            }
        }
    }

    int res = INF;
    for (int u = 1; u < n; u++)
        res = min(res, dp[(1 << n) - 1][u] + cost[u][0]);

    cout << "Min TSP cost: " << res << endl;

    /*
        ## Template ##
        int n;
        vector<int> dp(1 << n, INF);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) {
                    int new_mask = mask | (1 << j);
                    dp[new_mask] = min(dp[new_mask], dp[mask] + ...);
                }
            }
        }
    */
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
