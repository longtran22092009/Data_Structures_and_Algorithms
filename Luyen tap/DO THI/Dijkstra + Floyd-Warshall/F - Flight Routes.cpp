#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

int n, m, k;
vector <ll> ans, cnt(mxN); // Count the number of time vertic u is visited
vector <vector <pair <ll, ll>>> adj(mxN);

void Dijkstra(int s) {
    priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater<>> q;
    q.push({0, 1});

    while (!q.empty()) {
        ll u = q.top().second, dis = q.top().first;
        q.pop();

        ++cnt[u];
        if (cnt[u] > k) continue;
        if (u == n) ans.push_back(dis);

        for (auto &x : adj[u]) {
            ll v = x.first, w = x.second;
            q.push({dis + w, v});
        }
    }
}

void solve() {
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    Dijkstra(1);
    for (auto &x : ans) cout << x << " ";
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
