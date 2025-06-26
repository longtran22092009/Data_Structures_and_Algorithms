#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n, k; cin >> n >> k;

    vector <ll> a(n), b(n);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    ll ans = 0, new_quest = 0, maxVal = 0;
    for (ll i = 0; i < min(n, k); i++) {
        new_quest += a[i];
        maxVal = max(maxVal, b[i]);
        ans = max(ans, new_quest + maxVal * (k-i-1));
    }

    cout << ans << endl;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll t; cin >> t;
    while (t--)
        solve();
}
