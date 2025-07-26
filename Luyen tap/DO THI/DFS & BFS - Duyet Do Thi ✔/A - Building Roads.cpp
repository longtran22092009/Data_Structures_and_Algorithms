#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


ll n, m; 
vector <bool> vis;
vector <vector <ll>> adj;
vector <pair <ll, ll>> road;

void dfs(ll u) {
    vis[u] = 1;

    for (auto &v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

void countComponent() {
    ll cnt = 0;

    vector <ll> ans;
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans.push_back(i);
            ++cnt;
            dfs(i);
        }
    }

    cout << cnt-1 << endl;
    for (ll i = 1; i < ans.size(); i++) {
        cout << ans[0] << " " << ans[i] << endl;
    }
}

void solve() {
    cin >> n >> m;

    vis.resize(n+1, 0);
    adj.resize(n+1);

    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    countComponent();
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}
