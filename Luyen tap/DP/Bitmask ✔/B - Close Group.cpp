#include <bits/stdc++.h>
using namespace std;
//====== BITWISE ======//
#define MASK(i) (1LL << (i))
#define BIT(x, i) (1LL & ((x) >> (i)))
#define ON(x, i) ((x) | MASK(i))
#define OFF(x, i) ((x) & ~MASK(i))
#define LASTBIT(mask) ((mask) & -(mask))
#define SUBMASK(sub, mask) for (int sub = (mask); sub >= 1; sub = (sub - 1) & (mask))
//====== OTHER ======//
#define fi first
#define se second
#define ll long long
#define endl '\n'
#define all(x) begin(x), end(x)
#define mod(x, k) ((((x) % (k)) + (k)) % (k))
#define compress(c) sort(all(c)); c.erase(unique(all(c)), c.end());
#define Longgggg ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
//====== FILE ======//
#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"
//==================//

const int INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;
const ll MOD = (ll) 1e9+7;
const int mxN = MASK(20);

vector <bool> good(mxN, true);
vector <int> dp(mxN, INF); // dp[mask]: number of comps with mask
bool e[20][20];

void solve() {
    int n, m; cin >> n >> m;

    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        --u; --v;
        e[u][v] = e[v][u] = true;
    }

    // Check if subset of nodes mask is good or not
    FOR(mask, 1, MASK(n) - 1) {
        vector <int> nodes;
        FOR(i, 0, n - 1) if (BIT(mask, i)) 
            nodes.push_back(i);

        FOR(i, 0, nodes.size() - 1) FOR(j, i+1, nodes.size() - 1) {
            if (!e[nodes[i]][nodes[j]]) good[mask] = false;
        }
    }

    dp[0] = 0;
    FOR(mask, 1, MASK(n) - 1) {
        if (good[mask]) dp[mask] = 1;
        else {
            // dp[mask ^ sub]: mask of node in mask not in sub
            SUBMASK(sub, mask) dp[mask] = min(dp[mask], dp[sub] + dp[mask ^ sub]);
        }
    }

    cout << dp[MASK(n) - 1] << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }
    Longgggg

    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
