#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


ll n, m; 
vector <bool> vis;
vector <vector <ll>> adj;
vector <ll> parent;
vector <ll> dis;

void bfs(ll u) {
    queue <ll> q; q.push(u);
    vis[u] = 1;

    while (!q.empty()) {
        ll v = q.front(); q.pop();

        for (auto &x : adj[v]) {
            if (!vis[x]) {
                q.push(x);
                vis[x] = 1;

                dis[x] = dis[v]+1;
                parent[x] = v;
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    vis.resize(n+1, 0);
    adj.resize(n+1);
    parent.resize(n+1, 0);
    dis.resize(n+1, 0);

    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector <ll> path;
    ll curr_node = n;
    while (curr_node != 1ll) {
        path.push_back(curr_node);
        curr_node = parent[curr_node];
    }

    path.push_back(1);
    reverse(path.begin(), path.end());

    cout << dis[n]+1 << endl;
    for (auto &x : path) cout << x << " ";
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}
