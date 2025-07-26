#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    ll n; cin >> n;

    vector <vector <ll>> grid(n+1, vector <ll>(n+1));
    for (ll i = 1; i <= n; i++) {
        string s; cin >> s;
        for (ll j = 1; j <= n; j++) {
            grid[i][j] = s[j-1];
        }
    }

    vector <vector <ll>> dp(n+1, vector <ll>(n+1, 0));
    dp[0][1] = 1;
    // Clearer: dp[1][1] = (grid[1][1] != '*');

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (grid[i][j] == '*') continue;
            dp[i][j] += (dp[i][j-1] + dp[i-1][j]) % MOD;
        }
    }

    cout << dp[n][n] << endl;
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
