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

    vector <ll> dp(x+1, 0);
    dp[0] = 1; // Only one way is not using any coin

    for (ll i = 1; i <= x; i++) {
        for (auto &c : coin) {
            // From sum i-c to sum i by using coin c
            if (i-c >= 0) {
                dp[i] = (dp[i] + dp[i-c]) % MOD;
            }
        }
    }

    cout << dp[x] << endl;
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
