#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    ll n, m; cin >> n >> m;

    vector <ll> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <vector <ll>> dp(n+5, vector <ll>(m+5, 0));
    if (a[1] == 0) {
        // Any number from 1 to m is valid
        for (int v = 1; v <= m; v++) dp[1][v] = 1;
    } 
    else dp[1][a[1]] = 1; // First number valid only the case it got v = a[0]

    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            for (int v = 1; v <= m; v++) {
                dp[i][v] += dp[i-1][v];
                if (v-1 >= 1) dp[i][v] += dp[i-1][v-1];
                if (v+1 <= m) dp[i][v] += dp[i-1][v+1];
                dp[i][v] %= MOD;
            }
        }
        else {
            ll v = a[i];
            dp[i][v] += dp[i-1][v];
            if (v-1 >= 1) dp[i][v] += dp[i-1][v-1];
            if (v+1 <= m) dp[i][v] += dp[i-1][v+1];
            dp[i][v] %= MOD;
        }
    }

    ll ans = 0;
    for (int v = 1; v <= m; v++) {
        ans += dp[n][v];
        ans %= MOD;
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}