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

    vector <vector <int>> dp(n+1, vector <int>(m+1, 0));

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    ll i = n, j = m;
    string ans = "";

    while (i && j) {
        if (a[i-1] == b[j-1]) {
            ans += a[i-1];
            --i; --j;
        }
        else if (dp[i-1][j] > dp[i][j-1]) --i;
        else --j;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
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