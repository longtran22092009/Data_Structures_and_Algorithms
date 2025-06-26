#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 105, INF = (int) 1e9+5;
int m, n, k, mask[mxN];
string grid[mxN];

ll cal(int k) {
    int freq[26];
    memset(freq, 0, sizeof(freq));
    int l = 0, res = 0, diff = 0;

    for (int r = 0; r < n; r++) {
        // Add the col r
        for (int i = 0; i < 26; i++) {
            if (mask[r] & (1 << i)) { // Bit i is on
                if (++freq[i] == 1) ++diff;
            }
        }

        while (l <= r && diff > k) {
            // Remove the col l
            for (int i = 0; i < 26; i++) {
                if (mask[l] & (1 << i)) { // Bit i is on
                    if (--freq[i] == 0) --diff;
                }
            }
            ++l;
        }

        res += r-l+1;
    }
    return res;
}

void solve() {
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) cin >> grid[i];
    // All K-rectangle within rows in [top, bot]
    ll ans = 0;
    for (int top = 0; top < m; top++) {
        memset(mask, 0, sizeof(mask));
        for (int bot = top; bot < m; bot++) {
            // Change col to the bitmask
            for (int i = 0; i < n; i++) mask[i] |= 1 << (grid[bot][i] - 'A');
            // Count the K-rectangle = cal(K) - cal(K-1)
            ans += cal(k) - cal(k-1);
        }
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

    // ll t; cin >> t;
    // while (t--)
    solve();
}