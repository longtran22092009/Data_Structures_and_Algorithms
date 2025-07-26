#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    ll n, limit; cin >> n >> limit;

    vector <pair <ll, ll>> items(n+1);
    for (ll i = 1; i <= n; i++) cin >> items[i].first >> items[i].second;

    // dp[i][v]: i-th items with value v is weight dp[i][v]
    vector <vector <ll>> dp(n+1, vector <ll>(100001, 1000000005));
    for (ll i = 0; i <= n; i++) dp[i][0] = 0;

    for (ll i = 1; i <= n; i++) {
        for (ll v = 1; v <= 100000; v++) {
            dp[i][v] = min(dp[i][v], dp[i-1][v]);

            // From item have value v = items[i].second to value v using items i-th
            if (v - items[i].second >= 0) {
                // Min of weight
                dp[i][v] = min(dp[i][v], dp[i-1][v - items[i].second] + items[i].first);
            }
        }
    }

    // for (auto &x : dp[n]) cout << x << endl; 
    for (ll v = 100000; v >= 1; v--) {
        if (dp[n][v] <= limit) {
            cout << v << endl;
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