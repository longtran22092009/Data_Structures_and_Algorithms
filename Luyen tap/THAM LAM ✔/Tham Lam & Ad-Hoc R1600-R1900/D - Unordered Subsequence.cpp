#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    int mn = -1, mx = -1;
    for (int i = 1; i < n; i++) {
        if (mn != -1) {
            if (a[i] > a[mn]) {
                cout << "3\n1 " << mn+1 << " " << i+1 << endl;
                return;
            }
            else if (a[i] < a[mn]) mn = i;
        }
        else if (a[i] < a[0]) mn = i;

        if (mx != -1) {
            if (a[i] < a[mx]) {
                cout << "3\n1 " << mx+1 << " " << i+1 << endl;
                return;
            }
            else if (a[i] > a[mx]) mx = i;
        }
        else if (a[i] > a[0]) mx = i;
    }
    cout << "0\n";
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
