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
    vector<int> w(n+1), v(n+1), cnt(n+1); // w[i] = trọng lượng, v[i] = giá trị, cnt[i] = số vật có
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> cnt[i];

    // Binary splitting
    // Chuyển thành các vật được tạo từ x: 1, 2, 4, 8,..., 2^n vật ban đầu (x <= cnt[i])
    vector<int> new_weight, new_value;
    for (int i = 1; i <= n; i++) {
        int c = cnt[i];
        for (int k = 1; c > 0; k <<= 1) {
            int t = min(k, c);
            new_weight.push_back(w[i] * t);
            new_value.push_back(v[i] * t);
            c -= t;
        }
    }

    // Thành dạng 0/1 knapsack
    vector<int> dp(W+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
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
