#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 200005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

ll n, m;
vector <pair <ll, ll>> adj[mxN];

void Dijkstra(ll s) {
    priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater<>> q;
    vector <ll> d(mxN, LINF);
    d[s] = 0;
    q.push({0, s});

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

    for (int i = 1; i <= n; i++) cout << d[i] << " ";
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    Dijkstra(1);
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