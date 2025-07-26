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
    for (int i = 0; i < n; i++) {
        ++curr[a[i]];
        
        if (i >= k) {
            if (--curr[a[i-k]] <= 0) curr.erase(a[i-k]);
        } 
        if (i >= k-1) cout << curr.size() << " ";
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