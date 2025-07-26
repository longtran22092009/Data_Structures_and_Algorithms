#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


ll n, m;
bool valid = true;
vector <vector <ll>> adj;
vector <ll> a;
vector <bool> vis;

void bfs(ll u) {
    queue <ll> q; q.push(u);

    while (!q.empty()) {
        ll v = q.front(); q.pop();

        for (auto &x : adj[v]) {
            if (a[x] == 0) {
                a[x] = ((a[v] == 1)? 2 : 1);
                q.push(x);
            }

            else if (a[x] == a[v]) {
                valid = false;
                return;
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    adj.resize(n+1);
    a.resize(n+1, 0);
    vis.resize(n+1, 0);

    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        if (a[i] == 0) {
            a[i] = 1;
            bfs(i);
        }
    }

    if (valid) for (ll i = 1; i <= n; i++) cout << a[i] << " ";
    else cout << "IMPOSSIBLE\n";
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
