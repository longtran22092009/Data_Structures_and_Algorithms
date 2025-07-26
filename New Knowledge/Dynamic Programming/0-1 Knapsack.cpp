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
    vector<int> w(n+1), v(n+1); // w[i] = trọng lượng, v[i] = giá trị
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    // 2-D DP
    vector <vector <int>> dp(n+1, vector<int>(W+1, 0));
    // dp[i][j] = tối đa giá trị dùng i món đầu và sức chứa j
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i-1][j]; // Không lấy
            if (j >= w[i])
            dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]); // Lấy
        }
    }
    cout << dp[n][W] << endl;
    
    // 1-D DP
    vector<int> dp2(W+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp2[j] = max(dp2[j], dp2[j - w[i]] + v[i]);
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
