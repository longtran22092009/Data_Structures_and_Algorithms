#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "outofplace.in"
#define OUT "outofplace.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;

    vector <int> a(n+1), res;
    for (int i = 1; i <= n; i++) cin >> a[i];
    res = a;
    sort(res.begin(), res.end());

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == res[i]) continue;

        ++cnt;
        for (int j = i+1; j <= n; j++) {
            if (a[j] == res[i] && a[j] != res[j]) swap(a[i], a[j]);
        }
    }

    cout << cnt << endl;
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
