#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    ll n; cin >> n;

    vector <ll> dp(1000001, LONG_LONG_MAX);
    dp[n] = 0;

    for (ll i = n; i >= 0; i--) {
        if (dp[i] == LONG_LONG_MAX) continue;
        string s = to_string(i);

        for (auto &ch : s) {
            ll digit = ch - '0';
            ll new_num = i - digit;

            if (new_num >= 0) dp[new_num] = min(dp[new_num], dp[i] + 1);
        }
    }

    cout << dp[0] << endl;
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
