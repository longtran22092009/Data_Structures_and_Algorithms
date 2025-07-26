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
const int mxN = 20;

int a[mxN][mxN];
ll dp[MASK(mxN)], score[MASK(mxN)];

void solve() {
    int n; cin >> n;
    FOR(i, 0, n-1) FOR(j, 0, n-1) cin >> a[i][j];

    FOR(mask, 1, MASK(n)-1) {
        ll sum = 0;
        FOR(i, 0, n-1) if (BIT(mask, i)) {
            FOR(j, i+1, n-1) if (BIT(mask, j)) {
                sum += a[i][j];
            }
        }
        score[mask] = sum;
    }

    FOR(mask, 1, MASK(n)-1) SUBMASK(sub, mask)
        dp[mask] = max(dp[mask], dp[mask ^ sub] + score[sub]);

    cout << dp[MASK(n)-1] << endl;
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
