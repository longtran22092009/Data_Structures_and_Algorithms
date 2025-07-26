#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

void solve() {
    int n, m; cin >> n >> m;

    vector <ll> w(n+1), v(n+1), cnt(n+1);
    for (int i = 1; i <= n; i++) cin >> cnt[i] >> w[i] >> v[i];

    vector <ll> limit(m+1), cost(m+1);
    for (int i = 1; i <= m; i++) cin >> limit[i] >> cost[i];

    ll ans = -LINF;
    for (int id = 1; id <= m; id++) {
        ll W = limit[id];
        vector <pair <ll, ll>> items; // (w, v)

        for (int i = 1; i <= n; i++) {
            ll mx = min(cnt[i], W / w[i]);
            for (ll x = 1; mx > 0; x <<= 1) {
                ll take = min(mx, x);
                items.push_back({w[i] * take, v[i] * take});
                mx -= take;
            }
        }

        vector <ll> dp(W+1, 0);
        for (auto &x : items) {
            for (int i = limit[id]; i >= x.first; i--) {
                dp[i] = max(dp[i], dp[i - x.first] + x.second);
            }
        }

        ll maxProfit = *max_element(dp.begin(), dp.end());
        ans = max(ans, maxProfit - cost[id]);
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
    // clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}
