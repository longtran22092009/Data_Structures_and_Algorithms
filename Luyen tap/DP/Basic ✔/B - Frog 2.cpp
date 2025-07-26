#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n, k; cin >> n >> k;

    vector <ll> h(n+1), cost(n+1, LONG_LONG_MAX);
    for (ll i = 1; i <= n; i++) cin >> h[i];

    cost[1] = 0;
    for (ll i = 2; i <= n; i++) {
        for (ll j = 1; j <= min(k, i-1); j++) {
            cost[i] = min(cost[i], cost[i-j] + abs(h[i-j] - h[i]));
        }
    }

    cout << cost[n] << endl;
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
