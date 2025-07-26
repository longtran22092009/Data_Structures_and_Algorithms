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

    // dp[weight][value]
    vector <vector <ll>> dp(n+1, vector <ll>(limit+1, 0));

    for (ll i = 1; i <= n; i++) {
        // Choosing i-th item to take or not to the knapsack with weight = w
        for (ll w = 1; w <= limit; w++) {
            dp[i][w] = dp[i-1][w];

            // From the weight w - items[i].first to weight w by take the items[i]
            if (w - items[i].first >= 0) 
                dp[i][w] = max(dp[i][w], dp[i-1][w - items[i].first] + items[i].second);
        }
    }

    cout << dp[n][limit] << endl;
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