#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 200005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;

void solve() {
    int n, k; cin >> n >> k;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    // Initialize
    set <int> mex;
    unordered_map <int, int> curr;
    int mx = k-1; // First k element just missing one
    for (int i = 0; i <= mx; i++) mex.insert(i);
    // First sliding window
    for (int i = 0; i < k; i++) {
        ++curr[a[i]];
        if (mex.count(a[i])) mex.erase(a[i]);
    }
    
    if (mex.empty()) cout << mx+1 << " ";
    else cout << *mex.begin() << " ";

    for (int i = k; i < n; i++) {
        // Remove element that out of the window
        if (--curr[a[i-k]] <= 0) curr.erase(a[i-k]);
        if (!curr.count(a[i-k])) mex.insert(a[i-k]);
        // Add element that in the window
        ++curr[a[i]];
        mex.erase(a[i]);

        mx = max(mx, a[i]);
        if (mex.empty()) cout << mx+1 << " ";
        else cout << *mex.begin() << " ";
    }
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