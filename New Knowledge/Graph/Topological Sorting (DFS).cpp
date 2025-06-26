#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


ll n, m;
vector <vector <int>> adj;
bool vis[100005];
vector <int> topoOrder;

void topoSort(ll u) {
    vis[u] = true;

    for (auto &v : adj[u]) {
        if (!vis[v]) topoSort(v);
    }
    topoOrder.push_back(u);
}

void solve() {
    cin >> n >> m;

    adj.resize(n+1);
    fill(vis, vis + 100005, false);

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) topoSort(i);
    }

    reverse(topoOrder.begin(), topoOrder.end());
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
