#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "feast.in"
#define OUT "feast.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    ll limit, a, b; cin >> limit >> a >> b;

    vector <bool> dp(limit+1, false);
    dp[0] = true;

    // Eating orange or lemon before drinking water
    for (ll i = 1; i <= limit; i++) {
        if (i-a >= 0 && dp[i] == false) dp[i] = dp[i] || dp[i-a];
        if (i-b >= 0 && dp[i] == false) dp[i] = dp[i] || dp[i-b];
    }
    // Drink water
    for (ll i = 1; i <= limit; i++) {
        if (dp[i]) dp[i/2] = true;
    }
    // Continue eating after drink water
    for (ll i = 1; i <= limit; i++) {
        if (i-a >= 0 && dp[i] == false) dp[i] = dp[i] || dp[i-a];
        if (i-b >= 0 && dp[i] == false) dp[i] = dp[i] || dp[i-b];
    }

    for (ll i = limit; i >= 1; i--) {
        if (dp[i]) {
            cout << i << endl;
            return;
        }
    }
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