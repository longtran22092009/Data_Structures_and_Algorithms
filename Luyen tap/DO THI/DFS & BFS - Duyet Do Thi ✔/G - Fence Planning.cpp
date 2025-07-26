#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "fenceplan.in"
#define OUT "fenceplan.out"

ll n, m, ans = LONG_LONG_MAX;
ll mxx = 0, mnx = LONG_LONG_MAX, mxy = 0, mny = LONG_LONG_MAX;
vector <ll> ax, ay;
vector <vector <ll>> adj;
bool vis[100005];

void dfs(ll u) {
    vis[u] = true;

    mxx = max(mxx, ax[u]);
    mnx = min(mnx, ax[u]);
    mxy = max(mxy, ay[u]);
    mny = min(mny, ay[u]);

    for (auto &v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    cin >> n >> m;

    ax.resize(n+1);
    ay.resize(n+1);
    adj.resize(n+1);
    fill(vis, vis + 100005, false);

    for (ll i = 1; i <= n; i++) cin >> ax[i] >> ay[i];
    for (ll i = 1; i <= m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        if (vis[i]) continue;

        mxx = 0, mnx = LONG_LONG_MAX, mxy = 0, mny = LONG_LONG_MAX;
        dfs(i);

        ans = min(ans, ((mxx - mnx) + (mxy - mny)) * 2);
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