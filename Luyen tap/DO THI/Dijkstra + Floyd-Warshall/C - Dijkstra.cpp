#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005;
const ll INF = (ll) 1e18;
int n, m;
vector <pair <int, int>> adj[mxN];
int par[mxN];

void Dijkstra(int s) {
    vector <ll> d(n+1, INF);
    d[s] = 0;
    par[s] = s;

    priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater<>> q;
    q.push({0, s});

    while (!q.empty()) {
        pair <ll, int> top = q.top(); q.pop();
        int u = top.second;
        ll dis = top.first;

        if (dis > d[u]) continue;

        for (auto &e : adj[u]) {
            int v = e.first;
            ll w = e.second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                par[v] = u;
                q.push({d[v], v});
            }
        }
    }

    if (d[n] == INF) {
        cout << "-1\n";
        return;
    }
    
    vector <int> path;
    int curr =  n;
    while (curr != 1) {
        path.push_back(curr);
        curr = par[curr];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());
    for (auto &x : path) cout << x << " ";
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra(1);
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