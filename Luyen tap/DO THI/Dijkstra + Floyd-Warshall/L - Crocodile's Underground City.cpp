#include <bits/stdc++.h>
#define Longgggg ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define endl '\n'
using namespace std;
// Bitwise
#define MASK(i) (1LL << (i))
#define BIT(x, i) (1LL & ((x) >> (i)))
#define ON(x, i) ((x) | MASK(i))
#define OFF(x, i) ((x) & ~MASK(i))
#define LASTBIT(mask) ((mask) & -(mask))
// Other
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define mod(x, k) ((((x) % (k)) + (k)) % (k))
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;
const ll MOD = (ll) 1e9+7;
const int mxN = 100005;


ll travel_plan(int N, int M, int R[][2], int L[], int K, int P[]) {
    int n = N, m = M, k = K;

    vector <vector <pair <ll, ll>>> adj(n);
    FOR(i, 0, m-1) {
        adj[R[i][0]].push_back({R[i][1], L[i]});
        adj[R[i][1]].push_back({R[i][0], L[i]});
    }

    // Dijkstra from exits
    priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater<>> q;
    vector <ll> d(n, LINF); // Two shortest distance
    vector <int> vis(n, 0);

    FOR(i, 0, k-1) {
        q.push({0, P[i]});
        d[P[i]] = 0;
        vis[P[i]] = 1;
    }

    while (!q.empty()) {
        ll u = q.top().se, dis = q.top().fi; 
        q.pop();

        if (!vis[u]) {
            vis[u] = 1;
            continue;
        }

        if (u == 0) return dis;
        if (vis[u] > 1) continue;

        ++vis[u];
        for (auto &x : adj[u]) {
            ll v = x.fi, w = x.se;
            if (vis[v] > 1) continue;
            q.push({dis + w, v});
        }
    }

    return -1;
}

// void solve() {
//     int R[4][2] = {{0, 1}, {0, 2}, {3, 2}, {2, 4}};
//     int L[4] = {2, 3, 1, 4};
//     int P[3] = {1, 3, 4};
//     cout << travel_plan(5, 4, R, L, 3, P) << endl; // Output: 7

//     int R2[7][2] = {{0, 2}, {0, 3}, {3, 2}, {2, 1}, {0, 1}, {0, 4}, {3, 4}};
//     int L2[7] = {4, 3, 2, 10, 100, 7, 9};
//     int P2[2] = {1, 3};
//     cout << travel_plan(5, 7, R2, L2, 2, P2) << endl; // Output: 14
// }

// signed main() {
//     if (fopen(IN, "r")) {
//         freopen(IN, "r", stdin);
//         freopen(OUT, "w", stdout);
//         freopen(DEBUG, "w", stderr);
//     }
//     Longgggg

//     ll t = 1; 
//     // cin >> t;
//     while (t--) solve();
//     return 0;
// }