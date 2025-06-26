#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int m, n, k; cin >> m >> n >> k;

    vector <ll> a(m);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    vector <ll> pre(m);
    pre[0] = a[0];
    for (int i = 1; i < m; i++) pre[i] = pre[i-1] + a[i];

    ll ans = -2;
    for (int i = 0; i < m; i++) {
        if (i-n+1 >= 0 && a[i] - a[i-n+1] <= k) ans = max(ans, pre[i] - pre[i-n]);
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
