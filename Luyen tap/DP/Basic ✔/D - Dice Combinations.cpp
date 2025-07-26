#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    ll n; cin >> n;

    vector <ll> dp(n+1, 0);
    dp[0] = 1;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= 6; j++) {
            if (i-j >= 0) dp[i] = (dp[i] + dp[i-j]) % MOD; // From i we throw a j so it is one way more
        }
    }

    cout << dp[n] << endl;
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
