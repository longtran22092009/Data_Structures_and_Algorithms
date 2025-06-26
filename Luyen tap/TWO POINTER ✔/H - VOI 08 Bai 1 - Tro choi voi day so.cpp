#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;
    
    vector <int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(begin(a), end(a));
    sort(begin(b), end(b));

    int j = n-1;
    ll ans = (ll) 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, 1ll * abs(a[i] + b[j]));
        while (j-1 >= 0 && abs(a[i] + b[j-1]) <= abs(a[i] + b[j])) { // "<=" lmao
            ans = min(ans, 1ll * abs(a[i] + b[j-1]));
            --j;
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