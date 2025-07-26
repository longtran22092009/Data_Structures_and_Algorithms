#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 200005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

int n, m;

void Dijkstra(int s, vector <ll> &d, vector <vector <pair <int, int>>> &adj) {
    priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater<>> q;
    q.push({0, s});
    d[s] = 0;

    while (!q.empty()) {
        ll u = q.top().second, dis = q.top().first;
        q.pop();

        if (dis > d[u]) continue;
        for (auto &x : adj[u]) {
            ll v = x.first, w = x.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    vector <vector <pair <int, int>>> adj(n+1), r_adj(n+1);
    vector <ll> d(n+1, LINF), dn(n+1, LINF);
    
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        r_adj[v].push_back({u, w});
    }
    // Find distance from 1 to the others
    Dijkstra(1, d, adj);
    // Find distance from n to the others
    Dijkstra(n, dn, r_adj);

    ll ans = LINF;
    for (int i = 1; i <= n; i++) { // Edge (i, j);
        for (auto &j : adj[i]) {
            // Distant from 1 to i + [price/2] + from j to n
            ans = min(ans, d[i] + (j.second/2) + dn[j.first]);
        }
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    cerr << "Time: " << clock() - start << "ms\n";
}
