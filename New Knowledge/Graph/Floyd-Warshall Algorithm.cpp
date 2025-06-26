#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    # Floyd-Warshall Algorithm
    Time complexity: O(N^3)
*/


struct Edge {
    int u, v, w;
};

const int mxN = 105, INF = (int) 1e9;
int n, m;
vector <vector <int>> trace(mxN, vector <int>(mxN, INF)), d(mxN, vector <int>(mxN, INF)); // Truy vết đường đi
vector <Edge> edges;

void init_trace() {
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            trace[u][v] = u;
        }
    }
}

void Floyd(int a, int b) {
    init_trace(); // Khi cần truy vết đường đi
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (auto &e : edges) d[e.u][e.v] = e.w; // (u, v) = w
    
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (d[u][v] > d[u][k] + d[k][v]) {
                    d[u][v] = d[u][k] + d[k][v];
                    trace[u][v] = trace[k][v];
                }
            }
        }
    }
    
    // Truy vết đường đi
    vector<int> path;
    while (b != a) { // truy vết ngược từ v về u
        path.push_back(b);
        b = trace[a][b];
    }
    path.push_back(a);
    
    reverse(path.begin(), path.end()); // cần reverse vì đường đi từ v ngược về u
    for (auto &x : path) cout << x << " ";
    cout << endl;
}

void solve() {
    // n đỉnh, m cạnh
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    Floyd(1, 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << d[i][j] << " ";
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
