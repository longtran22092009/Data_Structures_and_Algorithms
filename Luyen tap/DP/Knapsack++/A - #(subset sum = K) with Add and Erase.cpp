#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

void solve() {
    int Q, k; cin >> Q >> k;
    vector <int> dp(5005, 0);
    dp[0] = 1;

    while (Q--) {
        char state; cin >> state;
        int val; cin >> val;

        if (state == '+') {
            for (int i = k; i >= val; i--) 
                dp[i] = (dp[i] + dp[i-val]) % MOD;
        }
        else {
            for (int i = val; i <= k; i++) 
                dp[i] = (dp[i] - dp[i-val] + MOD) % MOD;
        }

        cout << dp[k] << endl;
    }
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    // ll t; cin >> t;
    // while (t--)
    solve();
}