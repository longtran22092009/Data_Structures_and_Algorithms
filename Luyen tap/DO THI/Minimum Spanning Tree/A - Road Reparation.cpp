#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


struct Edge {
    int u, v;
    ll w;
};

const int mxN = 100005;
const ll INF = (ll) 1e18;
int n, m;
vector <Edge> edges;
int par[mxN], sz[mxN];

void make_set() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

void Kruskal() {
    make_set();
    vector <Edge> MST;
    ll d = 0;
    
    sort(edges.begin(), edges.end(), [&](Edge &a, Edge &b) { return a.w < b.w; });
    for (int i = 0; i < m; i++) {
        if (MST.size() == n-1) break;
        Edge e = edges[i];
        if (Union(e.u, e.v)) {
            MST.push_back(e);
            d += e.w;
        }
    }

    if (MST.size() != n-1) cout << "IMPOSSIBLE\n";
    else cout << d << endl;
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    Kruskal();
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