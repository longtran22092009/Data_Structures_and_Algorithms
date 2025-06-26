#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "milkorder.in"
#define OUT "milkorder.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    bool ok = false;
    vector <int> order(n+1, -1), a(m+1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        if (a[i] == 1) ok = true;
    }
    for (int i = 1; i <= k; i++) {
        int cow, pos; cin >> cow >> pos;
        order[pos] = cow;

        if (cow == 1) {
            cout << pos << endl;
            return;
        }
    }
    // Cow 1 is in the hierachy
    if (ok) {
        auto pos = order.begin()+1;
        for (int i = 1; i <= m; i++) {
            auto it = find(order.begin(), order.end(), a[i]);
            if (it == order.end()) { // Not in the list
                while (*pos != -1) ++pos;
                *pos = a[i];
            }
            else pos = it; // Already in the list
        }
        
        for (int i = 1; i <= n; i++) {
            if (order[i] == 1) {
                cout << i << endl;
                return;
            }
        }
    }
    // Otherwise
    auto pos = prev(order.end());
    for (int i = m; i >= 1; i--) {
        auto it = find(order.begin(), order.end(), a[i]);
        if (it == order.end()) { // Not in the list
            while (*pos != -1) --pos;
            *pos = a[i];
        }
        else pos = it; // Already in the list
    }

    for (int i = 1; i <= n; i++) {
        if (order[i] == -1) {
            cout << i << endl;
            return;
        }
    }
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
