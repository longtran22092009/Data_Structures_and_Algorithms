#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005;
const ll INF = (ll) 1e18;
int n, m;
vector <pair <ll, ll>> adj[mxN], r_adj[mxN];
vector <ll> d1, dn;

void Dijkstra(int s, vector <pair <ll, ll>> adj[]) {
    vector <ll> d(n+1, INF);
    d[s] = 0; 
    priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater<>> q;
    q.push({0, s});

    while (!q.empty()) {
        ll u = q.top().second, dis = q.top().first;
        q.pop();

        if (dis > d[u]) continue;
        for (auto &x : adj[u]) {
            ll v = x.first, w = x.second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v}); // lmao
            }
        }
    }

    if (s == 1) d1 = d;
    else dn = d;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        r_adj[v].push_back({u, w});
    }

    Dijkstra(1, adj);
    Dijkstra(n, r_adj);

    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        for (auto &x : adj[i]) {
            ans = min(ans, d1[i] + (x.second/2) + dn[x.first]);
        }
    }

    cout << ans << endl;
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
