#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    ll n, x; cin >> n >> x;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    int l = 0;
    ll sum = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];

        while (l <= r && sum > x) {
            sum -= a[l];
            ++l;
        }

        ans = max(ans, (ll) r-l+1);
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}
