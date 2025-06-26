#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

/*
    # Nếu đồ thị có chu trình thì thứ tự topo bằng thuật toán Kahn sẽ không có đủ đỉnh
    => Sử dụng để kiểm tra đồ thị có chu trình hay không

    VD: 7 8  => 1 7 6 (Có chu trình do không đủ đỉnh)
        1 2
        2 3
        2 4
        3 5
        4 5
        1 6
        7 6
        5 2
    
    VD: 7 7  => 1 7 2 6 3 4 5 (Không có chu trình do đủ đỉnh)
        1 2
        2 3
        2 4
        3 5
        4 5
        1 6
        7 6
*/

ll n, m;
vector <vector <int>> adj;
bool vis[100005];
vector <int> topoOrder, indeg;

void Kahn() {
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topoOrder.push_back(u);

        for (auto &v : adj[u]) {
            indeg[v]--;

            if (indeg[v] == 0) q.push(v);
        }
    }
}

void solve() {
    cin >> n >> m;

    adj.resize(n+1);
    indeg.resize(n+1, 0);
    fill(vis, vis + 100005, false);

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    Kahn();
    for (auto &x : topoOrder) cout << x << " ";
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
