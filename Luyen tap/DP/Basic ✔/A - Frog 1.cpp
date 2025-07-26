#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;

    vector <ll> h(n), cost(n, 0);
    for (auto &x : h) cin >> x;

    cost[0] = 0;
    cost[1] = cost[0] + abs(h[0] - h[1]);

    for (ll i = 2; i < n; i++) {
        // from cell i to cell i+1 or i+2
        cost[i] = min(cost[i-1] + abs(h[i-1] - h[i]), cost[i-2] + abs(h[i-2] - h[i]));
    }

    cout << cost[n-1] << endl;
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
