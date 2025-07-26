#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 505;
const ll INF = (ll) 1e15;
int n, m, Q;
vector <pair <int, int>> adj[mxN];
vector <vector <ll>> d(mxN, vector <ll>(mxN, INF));

void Floyd() {
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                // if (d[u][k] == INF && d[k][v] == INF) continue;
                if (d[u][v] > d[u][k] + d[k][v]) {
                    d[u][v] = d[u][k] + d[k][v];
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m >> Q;
    for (int i = 1; i <= m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    Floyd();
    for (int i = 1; i <= Q; i++) {
        int a, b; cin >> a >> b;

        if (d[a][b] == INF) cout << "-1\n";
        else cout << d[a][b] << endl;
    }
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}
