#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;

void solve() {
    int n, k; cin >> n >> k;

    vector <int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    map <int, int> freq;
    int ansl = -1, ansr = -1, len = 0;
    int l = 1;
    for (int r = 1; r <= n; r++) {
        ++freq[a[r]];

        while (l <= r && (int) freq.size() > k) {
            if (--freq[a[l]] == 0) freq.erase(a[l]);
            ++l;
        }

        if (r-l+1 > len) {
            ansl = l;
            ansr = r;
            len = r-l+1;
        }
    }

    cout << ansl << " " << ansr << endl;
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