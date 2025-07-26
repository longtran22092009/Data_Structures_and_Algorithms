#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 1000005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

void solve() {
    int n, m; cin >> n >> m;

    vector <pair <int, int>> a(n), b(m);
    for (auto &x : a) cin >> x.first >> x.second;
    for (auto &x : b) cin >> x.first >> x.second;

    vector <ll> dp1(mxN, (ll) -1e15), dp2(mxN, (ll) -1e15);
    dp1[0] = dp2[0] = 0;

    int sum1 = 0, sum2 = 0;
    for (auto &x : a) {
        sum1 += x.first;
        for (int i = sum1; i >= x.first; i--) {
            dp1[i] = max(dp1[i], dp1[i - x.first] + x.second);
        }
    }
    
    for (auto &x : b) {
        sum2 += x.first;
        for (int i = sum2; i >= x.first; i--) {
            dp2[i] = max(dp2[i], dp2[i - x.first] + x.second);
        }
    }

    ll ans = -LINF;
    for (int i = 0; i <= min(sum1, sum2); i++) ans = max(ans, dp1[i] + dp2[i]);
    cout << max(0ll, ans) << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();

    ll t; cin >> t;
    while (t--)
        solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}