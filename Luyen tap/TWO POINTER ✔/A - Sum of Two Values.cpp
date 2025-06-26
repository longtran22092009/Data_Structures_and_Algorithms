#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, x; cin >> n >> x;

    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());

    int l = 0, r = n-1;
    while (l < r) {
        if (a[l].first + a[r].first == x) {
            cout << a[l].second << " " << a[r].second << endl;
            return;
        }
        else if (a[l].first + a[r].first > x) --r;
        else ++l;
    }

    cout << "IMPOSSIBLE\n";
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
