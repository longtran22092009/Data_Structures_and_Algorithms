#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, m; cin >> n >> m;

    vector <int> a(n);
    for (auto &x : a) cin >> x;
    sort(begin(a), end(a));

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i+1, r = n-1;
        while (l < r) {
            ll sum = a[i] + a[l] + a[r];
            if (sum > m) --r;
            else {
                ans = max(ans, sum);
                ++l;
            } 
        }
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    // ll t; cin >> t;
    // while (t--)
    solve();
}