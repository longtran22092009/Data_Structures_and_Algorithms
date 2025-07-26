#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 200005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

int n, m, s, t;
vector <vector <pair <int, int>>> adj(mxN), radj(mxN), g(mxN);
vector <tuple <int, int, int>> edges;
vector <ll> ds(mxN, LINF), dt(mxN, LINF);

void Dijkstra(int s, vector <ll> &d, vector <vector <pair <int, int>>> &adj) {
    priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater<>> q;
    q.push({0, s});
    d[s] = 0;
    
    while (!q.empty()) {
        int u = q.top().second;
        ll dis = q.top().first;
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
}

int timeDfs = 0;
vector <int> num(mxN, 0), low(mxN, 0);
vector <bool> bridge(mxN, false), vis(mxN, false); // Multi-edges

void dfs(int u, int pre) {
    vis[u] = true;
    num[u] = low[u] = ++timeDfs;
    bool multiEdge = false;

    for (auto &x : g[u]) {
        int v = x.first, id = x.second;
        if (v == pre && multiEdge == false) {
            multiEdge = true;
            continue;
        }

        if (!vis[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > num[u]) bridge[id] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}

void findBridges() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, 0);
    }
}

void solve() {
    cin >> n >> m >> s >> t;    

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    Dijkstra(s, ds, adj);
    Dijkstra(t, dt, radj);

    // Build new graph with edges may be in all shortest path
    for (int i = 0; i < m; i++) {
        int u, v, w; tie(u, v, w) = edges[i];
        if (ds[u] + w + dt[v] == ds[t]) {
            g[u].push_back({v, i});
            g[v].push_back({u, i});
        }
    }
    
    findBridges();
    for (int i = 0; i < m; i++) {
        if (bridge[i]) cout << "YES\n";
        else {
            int u, v, w; tie(u, v, w) = edges[i];
            ll nw = ds[t] - ds[u] - dt[v] - 1, delta = w - nw;

            if (nw > 0) cout << "CAN " << delta << endl;
            else cout << "NO\n";
        }
    }
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}
