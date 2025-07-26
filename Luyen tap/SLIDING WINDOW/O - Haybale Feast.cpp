#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "hayfeast.in"
#define OUT "hayfeast.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;

void solve() {
    ll n, limit; cin >> n >> limit;

    vector <ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    ll l = 0, ans = LINF, sum = 0;
    map <ll, ll> freq;
    for (ll r = 0; r < n; r++) {
        ++freq[b[r]];
        sum += a[r];
        
        while (l <= r && sum >= limit) {
            ans = min(ans, freq.rbegin()->first);            
            if (--freq[b[l]] <= 0) freq.erase(b[l]);
            sum -= a[l];
            ++l;
        }
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