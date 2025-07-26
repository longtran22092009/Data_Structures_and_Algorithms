#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "talent.in"
#define OUT "talent.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

void solve() {
    int n, W; cin >> n >> W;

    int mxT = 0;
    vector <int> w(n+1), t(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> t[i];
        mxT += t[i];
    }

    vector <int> dp(mxT + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = mxT; j >= t[i]; j--) {
            dp[j] = min(dp[j], dp[j - t[i]] + w[i]);
        }
    }

    int ans = 0;
    for (int j = 0; j <= mxT; j++) {
        if (dp[j] >= W) ans = max(ans, j * 1000 / dp[j]);
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