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
const int mxN = 16;

void solve() {
    int n; cin >> n;

    vector <int> type(n), writer(n); // id
    vector <string> a(n), b(n), vals(n);
    FOR(i, 0, n-1) {
        cin >> a[i] >> b[i];
        vals.push_back(a[i]);
        vals.push_back(b[i]);
    }
    compress(vals);

    FOR(i, 0, n-1) {
        type[i] = lower_bound(all(vals), a[i]) - vals.begin();
        writer[i] = lower_bound(all(vals), b[i]) - vals.begin();
    }

    vector <vector <int>> dp(MASK(n), vector <int>(n, 0)); // true / false
    FOR(i, 0, n-1) dp[MASK(i)][i] = 1;
    FOR(mask, 0, MASK(n)-1) {
        // If it possible to reach this mask with last value is lst
        FOR(lst, 0, n-1) if (dp[mask][lst]) { 
            FOR(i, 0, n-1) if (!BIT(mask, i)) {
                if (type[lst] != type[i] && writer[lst] != writer[i]) continue;
                int nxt = mask | MASK(i);
                dp[nxt][i] |= dp[mask][lst];
            }
        }
    }

    int ans = 0; // Remain bits
    FOR(mask, 0, MASK(n)-1) {
        FOR(i, 0, n-1) if (dp[mask][i]) {
            ans = max(ans, __builtin_popcount(mask));
        }
    }

    cout << n - ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }
    Longgggg

    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
