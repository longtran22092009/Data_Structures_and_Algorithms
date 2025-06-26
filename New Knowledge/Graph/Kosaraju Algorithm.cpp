#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

/*
    Bước 1: Sắp xếp topo các đỉnh của đồ thị
    Bước 2: Tạo transpose graph
    Bước 3: Dfs theo thứ tự sắp xếp topo trên transpose graph
*/

ll n, m;
vector <vector <int>> adj, radj;
bool vis[100005];
stack <int> topo;

void topoSort(int u) {
    vis[u] = true;

    for (auto &v : adj[u]) {
        if (!vis[v]) topoSort(v);
    }
    topo.push(u);
}

void dfs(ll u) {
    cout << u << " ";
    vis[u] = true;

    for (auto &v : radj[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    cin >> n >> m;

    adj.resize(n+1);
    radj.resize(n+1);
    fill(vis, vis + 100005, false);
    
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) topoSort(i);
    }

    fill(vis, vis + 100005, false);
    while (!topo.empty()) {
        int u = topo.top(); topo.pop();

        if (!vis[u]) {
            dfs(u);
            cout << endl;
        }
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
