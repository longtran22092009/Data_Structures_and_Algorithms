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
    vector<int> w(n+1), v(n+1), val(n+1); // w[i] = trọng lượng, v[i] = thể tích, val[i] = giá trị
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> val[i];

    int maxWeight, maxVolume;
    vector<vector<int>> dp(maxWeight+1, vector<int>(maxVolume+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = maxWeight; j >= w[i]; j--) {
            for (int k = maxVolume; k >= v[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - w[i]][k - v[i]] + val[i]);
            }
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
