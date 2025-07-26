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
    int n, limit; cin >> limit >> n;

    vector <vector <pair <int, int>>> weights(limit+1);
    for (int i = 1; i <= n; i++) {
        int v, w, k; cin >> v >> w >> k;
        weights[w].push_back({v, k});
    }

    vector <pair <int, int>> items; // (w, v)
    for (int w = 1; w <= limit; w++) {
        // Priority for higher value
        sort(weights[w].begin(), weights[w].end(), greater<>());
        int mxPerWeight = limit / w;
        
        for (auto &it : weights[w]) {
            // Binary Decomposition
            int mx = min(it.second, mxPerWeight);
            mxPerWeight -= mx;
            
            for (ll d = 1; mx > 0; d <<= 1) {
                int take = min((ll)mx, d);
                items.push_back({w * take, it.first * take});
                mx -= take;
            }
            if (mxPerWeight <= 0) break;
        }
    }
    // for (auto &x : items) cerr << x.first << " " << x.second << endl;

    vector <ll> dp(limit + 1, 0);
    for (auto &it : items) {
        int w = it.first, v = it.second;
        for (int i = limit; i >= w; i--) {
            dp[i] = max(dp[i], dp[i - w] + v);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
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
