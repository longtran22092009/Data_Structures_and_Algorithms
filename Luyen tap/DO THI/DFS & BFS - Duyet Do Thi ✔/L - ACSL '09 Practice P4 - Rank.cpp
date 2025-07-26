#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


int n, k;
vector <vector <int>> adj;
vector <int> color, par;
bool vis[100005];
stack <int> topo;
set <int> ans;

void topoSort(int u) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) topoSort(v);
    }
    topo.push(u);
}

void dfs(int u) {
    color[u] = 1;
    for (auto &v : adj[u]) {
        if (color[v] == 0) {
            par[v] = u;
            dfs(v);
        }
        else if (color[v] == 1) {
            // Truy vết các đỉnh thuộc chu trình
            int st = u, ed = v;
            while (st != ed) {
                ans.insert(st);
                st = par[st];
            }
            ans.insert(st);
        }
    }
    color[u] = 2;
}

void solve() {
    cin >> n >> k;

    adj.resize(n+1);
    color.resize(n+1, 0);
    par.resize(n+1, 0);
    fill(vis, vis + 100005, false);

    for (int i = 1; i <= k; i++) {
        int u, v; cin >> u >> v;
        int a, b; cin >> a >> b;

        if (a > b) adj[u].push_back(v);
        else adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) dfs(i);
    }
    cout << ans.size() << endl;
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
