#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

ll n, m;
vector <ll> ans;
vector <vector <ll>> adj, radj;
bool vis[100005];
stack <ll> topo;

void topoSort(ll u) {
    vis[u] = true;

    for (auto &v : adj[u]) {
        if (!vis[v]) topoSort(v);
    }

    topo.push(u);
}

void dfs(ll u) {
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
    
    for (ll i = 1; i <= m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) topoSort(i);
    }

    fill(vis, vis + 100005, false);
    while (!topo.empty()) {
        ll node = topo.top(); topo.pop();
        if (vis[node]) continue;
        
        dfs(node);
        ans.push_back(node);
    }

    if (ans.size() == 1) cout << "YES\n";
    else cout << "NO\n" << ans[1] << " " << ans[0];
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