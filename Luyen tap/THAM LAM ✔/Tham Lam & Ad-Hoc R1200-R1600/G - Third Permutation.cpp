#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n ; cin >> n;

    if (n == 2) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector <int> a(n), b(n), c(n, -1);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    set <int> unused;
    for (int i = 1; i <= n; i++) unused.insert(i);

    for (int i = 0; i < n; i++) {
        for (auto &x : unused) {
            if (a[i] == x || b[i] == x) continue;
            c[i] = x;
            unused.erase(x);
            break;
        }

        if (c[i] == -1) {
            c[i] = *unused.begin();
            unused.erase(unused.begin());
        }
    }

    for (int i = n-2; i < n; i++) {
        if (a[i] == c[i] || b[i] == c[i]) {
            for (int j = 0; j < i; j++) {
                if (a[i] == c[j] || b[i] == c[j]) continue;
                if (a[j] == c[i] || b[j] == c[i]) continue;
                swap(c[i], c[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) cout << c[i] << " ";
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
