#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 10005, INF = (int) 1e9+5;
int n, m, Q, s;

void Dijkstra(int s, vector <pair <int, int>> adj[]) {
    vector <int> d(n+1, INF);
    d[s] = 0;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater<>> q;
    q.push({0, s});

    while (!q.empty()) {
        int u = q.top().second, dis = q.top().first;
        q.pop();

        if (dis > d[u]) continue;
        for (auto &x : adj[u]) {
            int v = x.first, w = x.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= Q; i++) {
        int x; cin >> x;
        if (d[x] == INF) cout << "Impossible\n";
        else cout << d[x] << endl;
    }
}

void solve() {
    while (cin >> n >> m >> Q >> s) {
        vector <pair <int, int>> adj[mxN];

        for (int i = 1; i <= m; i++) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({v, w});
            // adj[v].push_back({u, w});
        }
        Dijkstra(s, adj);
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
