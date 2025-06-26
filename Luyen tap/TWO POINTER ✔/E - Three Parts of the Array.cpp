#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;

    vector <ll> a(n);
    for (auto &x : a) cin >> x;

    int l = -1, r = n;
    ll sum1 = 0, sum2 = 0, mxId = 0;
    while (l < r) {
        if (sum1 < sum2) sum1 += a[++l];
        else if (sum1 > sum2) sum2 += a[--r];
        else {
            mxId = l;
            sum1 += a[++l];
            sum2 += a[--r];
        }
    }

    cout << accumulate(a.begin(), a.begin()+mxId+1, 0ll) << endl;
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