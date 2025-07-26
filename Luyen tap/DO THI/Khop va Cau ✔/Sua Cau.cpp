#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


// Thêm đường đi giữa hai đỉnh a, b
// => a->b là một chu trình => các cạnh trong chu trình không phải cạnh cầu
// Số cạnh cầu chính là số cạnh bị bỏ quên
const int mxN = 200005, INF = (int) 1e9+5;
int n, m;
int timeDfs = 0, bridge = 0;
int num[mxN], low[mxN];
unordered_set <int> adj[mxN];
unordered_map <int, int> vis;

void dfs(int u, int pre) {
    num[u] = low[u] = ++timeDfs;
    for (int v : adj[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u] && !(vis[u] == v) && !(vis[v] == u)) ++bridge;
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        vis.insert({a, b});
        adj[a].insert(b);
        adj[b].insert(a);
    }

    dfs(1, 1);
    cout << bridge << endl;
    // for (int i = 1; i <= n; i++) cout << num[i] << " " << low[i] << endl;
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
