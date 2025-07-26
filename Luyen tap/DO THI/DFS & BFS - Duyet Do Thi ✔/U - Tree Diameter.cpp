#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 200005;
int n;
vector <vector <int>> adj(mxN);
vector <int> dis(mxN, 0);
bool vis[mxN];

void dfs(int u) {
    vis[u] = true;

    for (auto &v : adj[u]) {
        if (!vis[v]) {
            dis[v] = dis[u] + 1;
            dfs(v);
        }
    }
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    int mxDis = -1, val = -1;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > mxDis) {
            mxDis = dis[i];
            val = i;
        }
    }

    fill(vis, vis + mxN, false);
    fill(dis.begin(), dis.end(), 0);
    dfs(val);
    
    cout << *max_element(dis.begin(), dis.end());
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