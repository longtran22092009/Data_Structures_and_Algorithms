#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 8, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

vector <ll> cnt(9);
bool dp[10][10005];
ll L = 840, sum = 0;

void solve() {
    ll W; cin >> W;

    for (int i = 1; i <= 8; i++) {
        cin >> cnt[i];
        sum += i * cnt[i];
    }
    if (sum <= W) {
        cout << sum << endl;
        return;
    }

    sum = 0;
    for (int i = 8; i >= 1; i--) {
        ll take = min(i * cnt[i], W), comb = L / i;
        // Using item wi to make item total weight is 840
        take = take / L * comb; // Total item wi need to use
        W -= take * i;
        sum += take * i;
        cnt[i] -= take;
        cnt[i] = min(cnt[i], L / i); // Try to just keep enough wi to make 840
    }

    dp[0][0] = 1;
    for (int i = 1; i <= 8; i++) {
        for (int j = 0; j <= cnt[i]; j++) {
            for (int k = i*j; k <= W; k++) {
                dp[i][k] |= dp[i-1][k - i*j];
            }
        }
    }

    for (int i = W; i >= 0; i--) {
        if (dp[8][i]) {
            cout << i + sum << endl;
            return;
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
