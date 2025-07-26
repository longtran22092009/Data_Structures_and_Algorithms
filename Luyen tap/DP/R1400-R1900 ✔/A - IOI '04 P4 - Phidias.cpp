#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 605, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

void solve() {
    int W, H, n; cin >> W >> H >> n;

    vector <vector <int>> dp(mxN, vector <int>(mxN, -1)); // Waste of rectangle (x, y)
    vector <pair <int, int>> a(n);
    for (auto &x : a) {
        cin >> x.first >> x.second;
        dp[x.first][x.second] = 0; // Need plate -> no cut
    }

    for (int w = 1; w <= W; w++) {
        for (int h = 1; h <= H; h++) {
            if (dp[w][h] != -1) continue;
            // Waste all the rectangle
            dp[w][h] = w*h;
            // Cut vertical at pos i in the rectangle
            for (int i = 1; i < w; i++) {
                dp[w][h] = min(dp[w][h], dp[i][h] + dp[w-i][h]);
            }
            // Cut horizontal at pos i in the rectangle
            for (int i = 1; i < h; i++) {
                dp[w][h] = min(dp[w][h], dp[w][i] + dp[w][h-i]);
            }
        }
    }

    cout << dp[W][H] << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    cerr << "Time: " << clock() - start << "ms\n";
}
