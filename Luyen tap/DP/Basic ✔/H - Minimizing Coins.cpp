#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    ll n, x; cin >> n >> x;

    vector <ll> coin(n);
    for (auto &x : coin) cin >> x;

    vector <ll> dp(x+1, LONG_LONG_MAX);
    dp[0] = 0;

    for (ll i = 1; i <= x; i++) {
        for (auto &c : coin) {
            // From sum i-c to sum i by using coin c
            if (i-c >= 0 && dp[i-c] != LONG_LONG_MAX) 
                dp[i] = min(dp[i], dp[i-c] + 1);    
        }
    }

    if (dp[x] == LONG_LONG_MAX) cout << "-1\n";
    else cout << dp[x] << endl;
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
