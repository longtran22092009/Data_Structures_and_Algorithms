#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 205, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

const int mxPw5 = 6000;
ll dp[mxN][mxPw5+1];
// dp[i][j]: i number, power of 5 = j -> power of 2

void solve() {
    int n, k; cin >> n >> k;

    vector <ll> a(n+1), pw2(n+1, 0), pw5(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (a[i] % 2 == 0) a[i] /= 2, ++pw2[i];
        while (a[i] % 5 == 0) a[i] /= 5, ++pw5[i];
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int id = 1; id <= n; id++) {
        for (int i = k; i >= 1; i--) {
            for (int j = mxPw5; j >= pw5[id]; j--) {
                if (dp[i-1][j - pw5[id]] != -1)
                    dp[i][j] = max(dp[i][j], dp[i-1][j - pw5[id]] + pw2[id]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= mxPw5; i++) {
        ans = max(ans, min(1ll * i, dp[k][i]));
    }
    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}