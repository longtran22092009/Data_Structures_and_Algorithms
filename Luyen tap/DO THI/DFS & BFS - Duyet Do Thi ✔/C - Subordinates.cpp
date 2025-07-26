#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


ll n; 
vector <bool> vis;
vector <vector <ll>> adj;
vector <ll> sub;

void dfs(ll u) {
    vis[u] = 1;

    ll numSub = 0;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            ++numSub;

            dfs(v);
            numSub += sub[v];
        }
    }

    sub[u] = numSub;
}

void solve() {
    cin >> n;

    vis.resize(n+1, 0);
    adj.resize(n+1);
    sub.resize(n+1, 0);

    for (ll i = 2; i <= n; i++) {
        ll u; cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    dfs(1);
    for (ll i = 1; i <= n; i++) cout << sub[i] << " ";
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
