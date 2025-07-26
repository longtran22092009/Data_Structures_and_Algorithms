#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    ll n; cin >> n;

    vector <ll> a(n);
    for (auto &x : a) cin >> x;

    vector <bool> dp(1e6+5, false);
    dp[0] = true;

    for (auto &x : a) {
        for (ll i = 1e6; i >= 1; i--) {
            if (dp[i]) dp[i+x] = true;
        }
        dp[x] = true;
    }

    vector <ll> ans;
    for (ll i = 1; i <= 1e6; i++) {
        if (dp[i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (auto &x : ans) cout << x << " ";
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