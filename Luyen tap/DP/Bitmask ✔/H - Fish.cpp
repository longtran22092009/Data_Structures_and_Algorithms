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
const int mxN = 18;

int n;
double a[mxN][mxN];
double dp[MASK(mxN)];

void solve() {
    setprecision(7); // 6 characters after decimal point
    cin >> n;
    FOR(i, 0, n-1) FOR(j, 0, n-1) cin >> a[i][j];

    // Prob i alive = prob i meet j * prob i eat j * prob j exist in mask
    // ... = dp[mask] * a[i][j] * 1/nC2 (take 1 pair in nC2 pairs)
    dp[MASK(n)-1] = 1;
    FORD(mask, MASK(n)-1, 0) {
        FOR(i, 0, n-1) if (BIT(mask, i)) { // Fish i will win
            FOR(j, 0, n-1) if (BIT(mask, j) && j != i) { // Fish i will meet fish j
                int alive = __builtin_popcount(mask);
                int nxt = OFF(mask, j);
                dp[nxt] += dp[mask] * a[i][j] / (alive * (alive-1) / 2);
            }
        }
    }

    FOR(i, 0, n-1) cout << dp[MASK(i)] << " ";
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
