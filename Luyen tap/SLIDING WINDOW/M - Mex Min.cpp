#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 2000005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;

void solve() {
    int n, m; cin >> n >> m;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    set <int> mex;
    unordered_map <int, int> freq;
    int ans = INF, mx = m-1;

    for (int i = 0; i <= mx; i++) mex.insert(i);
    for (int i = 0; i < m; i++) {
        ++freq[a[i]];
        if (mex.count(a[i])) mex.erase(a[i]);
    }

    if (mex.empty()) ans = min(ans, mx+1);
    else ans = min(ans, *mex.begin());

    for (int i = m; i < n; i++) {
        // Remove
        if (--freq[a[i-m]] <= 0) {
            freq.erase(a[i-m]);
            mex.insert(a[i-m]);
        }
        // Add
        ++freq[a[i]];
        mex.erase(a[i]);

        mx = max(mx, a[i]);
        if (mex.empty()) ans = min(ans, mx+1);
        else ans = min(ans, *mex.begin());
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