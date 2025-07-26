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

    vector<int> dp(W+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] += dp[j - w[i]];
        }
    }
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "j", stdout);
        freopen(DEBUG, "j", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}
