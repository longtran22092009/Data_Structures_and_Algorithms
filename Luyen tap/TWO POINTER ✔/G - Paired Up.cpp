#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "pairup.in"
#define OUT "pairup.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;

    vector <pair <ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        int freq, x; cin >> freq >> x;
        a[i] = {x, freq};
    }
    sort(a.begin(), a.end());
    // for (int i = 0; i < n; i++) cout << a[i].first << " " << a[i].second << endl;
    
    int l = 0, r = n-1;
    ll ans = 0;

    while (l <= r) {
        // cout << l << " " << r << endl;
        ll sum = a[l].first + a[r].first;
        ans = max(ans, sum);
        
        a[l].second--;
        a[r].second--;
        if (a[l].second == 0) ++l;
        if (a[r].second == 0) --r;
    }

    cout << ans << endl;
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