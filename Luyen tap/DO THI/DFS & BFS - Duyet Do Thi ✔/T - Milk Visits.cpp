#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "milkvisits.in"
#define OUT "milkvisits.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;

int n, m;
string breed;
vector <vector <int>> adj(mxN);
int comps[mxN];

void dfs(int u, int id) {
    comps[u] = id;

    for (auto &v : adj[u]) {
        if (!comps[v] && breed[u-1] == breed[v-1]) {
            comps[v] = id;
            dfs(v, id);
        }
    }
}

void solve() {
    cin >> n >> m >> breed;

    for (int i = 1; i <= n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Precompute
    int id = 1;
    for (int i = 1; i <= n; i++) {
        if (!comps[i]) dfs(i, id++);
    }

    while (m--) {
        int u, v; cin >> u >> v;
        char req; cin >> req;
        // Different component => should go pass both type of milk -> always happy
        // Same component => if the milk type is the same -> happy else -> unhappy
        if (comps[u] != comps[v] || breed[u-1] == req) cout << "1";
        else cout << "0";
    }
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    // ll t; cin >> t;
    // while (t--)
    solve();
}