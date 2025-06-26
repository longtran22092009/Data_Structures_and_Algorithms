#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

/*
    # Dijkstra Algorithm
    Time complexity: O((E+V) logV)
*/
const int mxN = 10005, INF = (int) 1e9;
int n, m, s;
vector <pair <int, int>> adj[mxN]; // Mảng tĩnh các vector (truy cập nhanh hơn)
int pre[mxN];

void Dijkstra(int s, int t) {
    vector <ll> d(n+1, INF);
    d[s] = 0;
    pre[s] = s;

    // pair <int, int> {dis, to_node};
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q;
    q.push({0, s});

    while (!q.empty()) {
        pair <int, int> top = q.top(); q.pop();
        int u = top.second, dis = top.first;
        if (dis > d[u]) continue; // Đỉnh u đã được cập nhật một đường đi ngắn hơn
        
        // Cập nhật khoảng cách từ s đến mọi đỉnh kề với u
        for (auto &x : adj[u]) {
            int v = x.first, w = x.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pre[v] = u;
                q.push({d[v], v});
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << d[i] << " ";
    // }
    cout << d[t] << endl;
    vector <int> path;
    while (true) {
        path.push_back(t);
        t = pre[t];
        if (t == s) break;
    }
    path.push_back(s);
    reverse(path.begin(), path.end());

    for (auto &x : path) cout << x << " ";
}

void solve() {
    cin >> n >> m >> s;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    Dijkstra(s, n);
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