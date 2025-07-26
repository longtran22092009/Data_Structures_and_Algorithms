#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "fencedin.in"
#define OUT "fencedin.out"
#define DEBUG "debug.out"


struct Edge {
    int u, v, w;
};

const int mxN = 2005, INF = (int) 1e9+5;
const int MOD = (int) 1e9+7, LINF = (int) 1e18;

int A, B, n, m, V, E;
vector <Edge> edges;
vector <int> a(mxN, 0), b(mxN, 0);
int par[mxN*mxN], sz[mxN*mxN];

// DSU
void make_set() {
    for (int i = 1; i <= V; i++) {
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
    ll d = 0;
    sort(edges.begin(), edges.end(), [&](Edge &a, Edge &b) { return a.w < b.w; });

    for (auto &e : edges) {
        if (Union(e.u, e.v)) d += e.w;
    }
    cout << d << endl;
}

void solve() {
    cin >> A >> B >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    a[0] = 0;
    b[0] = 0;
    a[n+1] = A;
    b[m+1] = B;
    sort(a.begin(), a.begin()+n+2);
    sort(b.begin(), b.begin()+m+2);
    // Vertical edges
    for (int i = 1; i <= n+1; i++) {
        for (int j = 1; j <= m; j++) {
            int dis = a[i] - a[i-1];
            edges.push_back({i + (j-1)*(n+1), i + j*(n+1), dis});
        }
    }
    // Horizontal edges
    for (int i = 1; i <= m+1; i++) {
        for (int j = 1; j <= n; j++) {
            int dis = b[i] - b[i-1];
            edges.push_back({j + (i-1)*(n+1), j+1 + (i-1)*(n+1), dis});
        }
    }

    V = (n+1)*(m+1);
    Kruskal();
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    // int t; cin >> t;
    // while (t--)
    solve();
}