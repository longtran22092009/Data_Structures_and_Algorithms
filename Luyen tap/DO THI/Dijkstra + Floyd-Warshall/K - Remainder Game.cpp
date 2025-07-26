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
const int mxN = 51;

vector <int> use(mxN, 1);
ll d[mxN][mxN];

void floyd() {
    FOR(i, 0, mxN-1) FOR(j, 0, mxN-1) 
        d[i][j] = (i == j ? 0 : LINF);

    FOR(k, 1, mxN-1) if (use[k]) {
        FOR(i, 0, mxN-1) {
            d[i][i % k] = 1;
        }
    }

    FOR(k, 0, mxN-1) FOR(i, 0, mxN-1) FOR(j, 0, mxN-1)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void solve() {
    int n; cin >> n;

    vector <int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    floyd();
    FOR(i, 0, n-1) if (d[a[i]][b[i]] == LINF) {
        cout << "-1\n";
        return;
    }

    FORD(k, mxN-1, 1) {
        use[k] = 0; // Thu khong dung k nay
        floyd();
        
        bool ok = true;
        FOR(i, 0, n-1) if (d[a[i]][b[i]] == LINF) {
            ok = false;
            break;
        }

        if (!ok) use[k] = 1; // Khong the bo k nay duoc
    }

    ll ans = 0;
    FOR(k, 1, mxN-1) if (use[k]) ans += MASK(k);
    cout << ans << endl;
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