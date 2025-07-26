#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "wormsort.in"
#define OUT "wormsort.out"
#define DEBUG "debug.out"


struct Edge {
    ll x, y, w;
};

const int mxN = 100005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;
ll n, m;
vector <ll> a(mxN), pos(mxN), coms(mxN);
vector <Edge> edges(mxN);
vector <vector <ll>> adj(mxN);
bool vis[mxN];

void dfs(int u, ll cnt) {
    vis[u] = true;
    coms[u] = cnt;

    for (auto &v : adj[u]) {
        if (!vis[v]) dfs(v, cnt);
    }
}

bool check(ll mid) {
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= m; i++) {
        // Just keep the edge with the valid width
        if (edges[i].w >= mid) {
            ll x = edges[i].x, y = edges[i].y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    fill(vis, vis+mxN, false);
    fill(coms.begin(), coms.end(), 0);
    // Check all connected component
    ll cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, cnt);
            ++cnt;
        }
    }
    // If the value i and the position i are in the same component => valid
    // Else they can't swap in some way to get in correct order
    for (int i = 1; i <= n; i++) {
        if (coms[i] != coms[pos[i]]) return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        ll x, y, w; cin >> x >> y >> w;
        edges[i] = {x, y, w};
    }
    // Already ordered
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (pos[i] != i) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "-1\n";
        return;
    }

    // Binary search for the maximum width of the least wide
    ll l = 1, r = LINF, ans = -1;
    while (l <= r) {
        ll mid = (l+r)/2;

        if (check(mid)) {
            ans = mid;
            l = mid+1; // Maximized
        }
        else r = mid-1; // Too wide
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

    // ll t; cin >> t;
    // while (t--)
    solve();
}