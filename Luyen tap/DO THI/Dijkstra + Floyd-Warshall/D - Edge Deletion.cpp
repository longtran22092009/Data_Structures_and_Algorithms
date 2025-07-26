#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


struct Edge {
    ll u, v, w;
};

const int mxN = 305, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

int n, m;
vector <Edge> edges;
vector <vector <ll>> d(mxN, vector <ll>(mxN, LINF));

void Floyd() {
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (d[u][k] == LINF || d[k][v] == LINF) continue;
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
        d[u][v] = w;
        d[v][u] = w;
    }

    Floyd();
    ll ans = 0;
    for (auto &e : edges) {
        // If delete edge e it still should be a path between e.u and e.v shortest
        for (int i = 1; i <= n; i++) {
            if (i == e.u || i == e.v) continue;
            if (d[e.u][i] + d[i][e.v] <= e.w) {
                ++ans;
                break;
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
    clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    cerr << "Time: " << clock() - start << "ms\n";
}
