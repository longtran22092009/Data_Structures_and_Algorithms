#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18, MOD = (ll) 1e9+7;

vector <vector <ll>> adj(mxN), dp(mxN, vector <ll>(2));
bool vis[mxN];

void dfs(int u) {
    vis[u] = true;
    dp[u][0] = dp[u][1] = 1;

    for (auto &v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
            
            dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % MOD;
            dp[u][1] = dp[u][1] * dp[v][0] % MOD;
        }
    }
}

void solve() {
    int n; cin >> n;

    for (int i = 1; i <= n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
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
