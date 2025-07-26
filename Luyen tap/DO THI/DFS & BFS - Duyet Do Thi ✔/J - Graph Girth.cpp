#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


ll n, m, ans = LONG_LONG_MAX;
vector <vector <ll>> adj;

void bfs(ll start) {
    vector <ll> dis(10005, -1);
    vector <ll> par(10005, 0);

    queue <ll> q;
    q.push(start);
    dis[start] = 0;

    while (!q.empty()) {
        ll v = q.front(); q.pop();

        for (auto &x : adj[v]) {
            if (dis[x] == -1) {
                dis[x] = dis[v] + 1;
                par[x] = v;
                q.push(x);
            }

            else if (x != par[v]) ans = min(ans, dis[v] + dis[x] + 1);
        }
    }
}

void solve() {
    cin >> n >> m;

    adj.resize(n+1);

    for (ll i = 1; i <= m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // i is the start node of the cycle
    for (ll i = 1; i <= n; i++) {
        bfs(i);
    }

    if (ans == LONG_LONG_MAX) cout << "-1\n";
    else cout << ans << endl;
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
