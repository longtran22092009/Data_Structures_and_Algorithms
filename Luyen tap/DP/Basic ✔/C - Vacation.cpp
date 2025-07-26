#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;

    vector <vector <ll>> point(n+1, vector <ll>(3, 0)), dp(n+1, vector <ll>(3, 0));

    for (ll i = 1; i <= n; i++) cin >> point[i][0] >> point[i][1] >> point[i][2];

    dp[1][0] = point[1][0];
    dp[1][1] = point[1][1];
    dp[1][2] = point[1][2];

    for (ll i = 2; i <= n; i++) {
        // Choose one of three activities
        dp[i][0] = point[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = point[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = point[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
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
