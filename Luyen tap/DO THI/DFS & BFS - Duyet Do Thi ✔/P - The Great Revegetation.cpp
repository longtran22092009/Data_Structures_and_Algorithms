#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "revegetate.in"
#define OUT "revegetate.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;
int n, m;
vector <vector <pair <int, char>>> adj(mxN);
int grass[mxN];
bool valid = true;

void dfs(int u, int type) {
    grass[u] = type;

    for (auto &x : adj[u]) {
        int choose = ((x.second == 'S')? type : 1-type);
        if (grass[x.first] == -1) dfs(x.first, choose);
        // e.g 1,2,3 are same before then 1,3 different is invalid
        // => we can't create any valid way
        else if (grass[x.first] != choose) {
            valid = false;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char op; cin >> op;
        int u, v; cin >> u >> v;
        adj[u].push_back({v, op});
        adj[v].push_back({u, op});
    }

    fill(grass, grass+mxN, -1);
    int k = 0;

    for (int i = 1; i <= n; i++) {
        if (grass[i] == -1) {
            dfs(i, 0);

            if (!valid) {
                cout << "0\n";
                return;
            }
            ++k;
        }
    }

    // Each component will have two ways => 2^k ways in total with k is number of component
    cout << "1";
    for (int i = 1; i <= k; i++) cout << "0";
    cout << endl;
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