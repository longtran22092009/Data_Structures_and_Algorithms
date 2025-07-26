#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 10005;
int n, m;
int timeDfs, bridge;
int num[mxN], low[mxN];
bool joint[mxN];
vector <int> adj[mxN];

void dfs(int u, int pre) {
    int child = 0; // Con cua not u
    num[u] = low[u] = ++timeDfs;

    for (auto &v : adj[u]) {
        if (v == pre) continue;

        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            // Kiem tra canh cau
            if (low[v] == num[v]) ++bridge;
            ++child;
            // Kiem tra dinh tru (khop)
            if (u == pre) {
                if (child > 1) joint[u] = true;
            }
            else if (low[v] >= num[u]) joint[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }

}

void solve() {
    // n đỉnh, m cạnh
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!num[i]) dfs(i, i);
    }

    int cntJoint = 0;
    for (int i = 1; i <= n; i++) cntJoint += joint[i];

    cout << cntJoint << " " << bridge << endl;
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
