#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "herding.in"
#define OUT "herding.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;

    vector <int> a(n);
    for (auto &x : a) cin >> x;
    sort(begin(a), end(a));

    int mn = INT32_MAX, mx;
    // Case 1: XXXX__X
    if (a[n-2] - a[0] == n-2 && a[n-1] - a[n-2] > 2) mn = 2;
    // Case 2: X__XXXX
    else if (a[n-1] - a[1] == n-2 && a[1] - a[0] > 2) mn = 2;
    else {
        int r = 0, maxRange = 0;
        for (int l = 0; l < n; l++) {
            while (r < n-1 && a[r+1] - a[l] < n) ++r;
            maxRange = max(maxRange, r-l+1); // The range with most cow in place
        }
        mn = n - maxRange;
    }
    // Max distance between two last cow and two first cow to the others
    // minus n-2 cow already in place
    mx = max(a[n-2] - a[0], a[n-1] - a[1]) - (n-2); 
    cout << mn << endl << mx << endl;
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