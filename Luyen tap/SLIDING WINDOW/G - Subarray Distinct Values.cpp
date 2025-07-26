#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, k; cin >> n >> k;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    unordered_map <int, int> curr;
    int l = 0;
    ll ans = 0;
    for (int r = 0; r < n; r++) {
        ++curr[a[r]];

        while (l <= r && curr.size() > k) {
            if (--curr[a[l]] <= 0) curr.erase(a[l]);
            ++l;
        }
        ans += r-l+1;
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