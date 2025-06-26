#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 1000005, INF = (int) 1e9+5;
int n, L, D;
vector <ll> a(mxN);

ll cal(int limit) {
    ll l = 0, res = 0;
    map <int, int> freq;
    for (ll r = 0; r < n; r++) {
        ++freq[a[r]];
        while (l <= r && (1ll* (freq.rbegin()->first - freq.begin()->first) > D || r-l+1 > limit)) {
            if (--freq[a[l]] == 0) freq.erase(a[l]);
            ++l;
        }
        res += r-l+1;
        // cerr << limit << " " << res << endl;
    }
    // cerr << "Result: " << res << endl;
    return res;
}

void solve() {
    cin >> n >> L >> D;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = cal(n) - cal(L); // length of L point = L-1
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