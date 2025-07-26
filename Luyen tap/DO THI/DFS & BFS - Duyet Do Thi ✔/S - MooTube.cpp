#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "mootube.in"
#define OUT "mootube.out"
#define DEBUG "debug.out"

const int mxN = 5005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;

int n, Q;
vector <vector <pair <int, int>>> adj(mxN);
int ans[mxN][mxN];

void bfs(int u) {
    vector <bool> vis(mxN, false);
    queue <pair <int, int>> q; q.push({u, INF});
    vis[u] = true;

    while (!q.empty()) {
        int v = q.front().first, x = q.front().second;
        q.pop();

        for (auto &p : adj[v]) {
            if (!vis[p.first]) {
                vis[p.first] = true;

                int nx = min(x, p.second);
                ans[u][p.first] = nx;
                q.push({p.first, nx});
            }
        }
    }
}

void solve() {
    cin >> n >> Q;

    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n-1; i++) {
        int u, v, val; cin >> u >> v >> val;
        adj[u].push_back({v, val});
        adj[v].push_back({u, val});
    }
    // Precompute
    for (int i = 1; i <= n; i++) bfs(i);

    while (Q--) {
        int k, v; cin >> k >> v;

        int res = 0;
        for (int i = 1; i <= n; i++) res += (ans[v][i] >= k);
        cout << res << endl;
    }
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