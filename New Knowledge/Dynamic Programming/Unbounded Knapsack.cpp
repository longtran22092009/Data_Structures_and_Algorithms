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
    int n, W; // Số lượng đồ, trọng lượng tối đa
    cin >> n >> W;
    vector<int> weight(n+1), value(n+1); // weight[i] = trọng lượng, value[i] = giá trị
    for (int i = 1; i <= n; i++) cin >> weight[i] >> value[i];

    vector<int> dp(W+1, 0);
    for (int w = 0; w <= W; ++w) {
        for (int i = 0; i < n; ++i) {
            if (w >= weight[i])
                dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
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
