#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    string a, b; cin >> a >> b;
    ll n = (ll) a.size(), m = (ll) b.size();

    vector <vector <int>> dp(n+1, vector <int>(m+1, 1e9+5));
    dp[0][0] = 0;

    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= m; j++) {
            // delete a[i-1] => a[:i-1] to b[:j] it costs 1 operation
            if (i) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            // add b[j-1] => a[:i] to b[:j-1] it costs 1 operation
            if (j) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            // replace a[i-1] => a[:i-1] to b[:j-1] it costs 1 operation
            if (i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1]));
        }
    }

    cout << dp[n][m] << endl;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}