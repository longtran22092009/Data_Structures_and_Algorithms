#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;

    vector <int> coins(n);
    for (auto &x : coins) cin >> x;

    bool dp[505][505]; // dp[s][x]: tong s co tong x
    dp[0][0] = true;

    for (auto &c : coins) {
        // Duyet cac tong s
        for (int s = k; s >= 0; s--) {
            // Duyet cac gia tri x
            for (int x = 0; x <= k; x++) {
                if (!dp[s][x]) continue; // Neu tong s ko co tong x

                // Them dong xu c vao tong hien co
                if (s + c <= k) {
                    dp[s+c][x] = true;
                    if (x + c <= k) dp[s+c][x+c] = true;
                }
            }
        }
    }

    set <int> ans;
    for (int x = 0; x <= k; x++) {
        if (dp[k][x]) ans.insert(x);
    }

    cout << ans.size() << endl;
    for (auto &x : ans) cout << x << " ";
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}