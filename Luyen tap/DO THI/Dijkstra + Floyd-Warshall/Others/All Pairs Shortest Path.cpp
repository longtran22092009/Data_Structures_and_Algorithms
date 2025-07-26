#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 1005, INF = (int) 1e9;
int n, m, Q;

void Floyd(vector <vector <int>> &d) {
    for (int i = 0; i <= n-1; i++) d[i][i] = 0;
    
    for (int k = 0; k <= n-1; k++) {
        for (int u = 0; u <= n-1; u++) {
            for (int v = 0; v <= n-1; v++) {
                if (d[u][k] == INF || d[k][v] == INF) continue;
                if (d[u][v] > d[u][k] + d[k][v]) {
                    d[u][v] = d[u][k] + d[k][v];
                }
            }
        }
    }

    // Check if are there any negative cycle
    for (int k = 0; k < n; k++) {
        if (d[k][k] == 0) continue;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (d[u][k] < INF && d[k][v] < INF)
                    d[u][v] = -INF;
            }
        }
    }
}

void solve() {
    while (cin >> n >> m >> Q) {
        vector <vector <int>> d(mxN, vector <int>(mxN, INF));

        for (int i = 1; i <= m; i++) {
            int u, v, w; cin >> u >> v >> w;
            d[u][v] = min(d[u][v], w);
        }
        
        Floyd(d);
        for (int i = 1; i <= Q; i++) {
            int a, b; cin >> a >> b;
            
            if (d[a][b] == INF) cout << "Impossible\n";
            else if (d[a][b] == -INF) cout << "-Infinity\n";
            else cout << d[a][b] << endl;
        }
        cout << endl;
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
