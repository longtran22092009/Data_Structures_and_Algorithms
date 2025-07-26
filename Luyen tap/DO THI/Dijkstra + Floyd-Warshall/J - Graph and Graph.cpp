#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 1005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18, MOD = (ll) 1e9+7;

int n, s1, s2, m1, m2;
vector <int> adj1[mxN], adj2[mxN];
set <pair <int, int>> edges;
vector <bool> good(mxN, false); 
vector <vector <int>> d(mxN+1, vector <int>(mxN+1, INF));

void Dijkstra() {
    priority_queue <tuple <int, int, int>, vector <tuple <int, int, int>>, greater<>> q;
    q.push({0, s1, s2});
    d[s1][s2] = 0;

    while (!q.empty()) {
        int u1, u2, dis; tie(dis, u1, u2) = q.top();
        q.pop();

        if (dis > d[u1][u2]) continue;
        for (auto &v1 : adj1[u1]) {
            for (auto &v2 : adj2[u2]) {
                int w = abs(v1 - v2);
                if (d[v1][v2] > d[u1][u2] + w) {
                    d[v1][v2] = d[u1][u2] + w;
                    q.push({d[v1][v2], v1, v2});
                }
            }
        }
    }
}

void solve() {
    cin >> n >> s1 >> s2 >> m1;
    for (int i = 1; i <= m1; i++) {
        int u, v; cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
        edges.insert({min(u, v), max(u, v)});
    }
    
    cin >> m2;
    for (int i = 1; i <= m2; i++) {
        int u, v; cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        if (edges.count({min(u, v), max(u, v)})) {
            good[u] = true;
            good[v] = true;
        }
    }
    
    Dijkstra();
    
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        if (good[i]) ans = min(ans, d[i][i]);
    }
    
    cout << (ans == INF ? -1 : ans) << endl;
    // Reset
    for (int i = 1; i <= n; i++) {
        adj1[i].clear();
        adj2[i].clear();
        fill(d[i].begin(), d[i].end(), INF);
    }

    edges.clear();
    fill(good.begin(), good.end(), false);
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();

    ll t; cin >> t;
    while (t--)
        solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}
