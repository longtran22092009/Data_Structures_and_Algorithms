#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "poetry.in"
#define OUT "poetry.out"
#define DEBUG "debug.out"


const int mxN = 5005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

int n, m, k;
vector <pair <int, int>> words;
vector <ll> dp(mxN, 0);

ll powMod(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b) {
        if (b % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void solve() {
    cin >> n >> m >> k;

    words.resize(n);
    for (int i = 0; i < n; ++i) {
        int si, ci; cin >> si >> ci;
        words[i] = {si, ci};
    }

    vector <int> scheme(26);
    for (int i = 0; i < m; ++i) {
        char ch; cin >> ch;
        scheme[ch - 'A']++;
    }

    dp[0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (auto &x : words) {
            if (i - x.first >= 0)
                dp[i] = (dp[i] + dp[i - x.first]) % MOD;
        }
    }

    map<int, ll> ending;
    for (auto &x : words) {
        if (x.first <= k) {
            int remain = k - x.first;
            ending[x.second] = (ending[x.second] + dp[remain]) % MOD;
        }
    }

    ll ans = 1;
    for (int i = 0; i < 26; i++) {
        if (scheme[i] == 0) continue;

        ll sum = 0;
        for (auto &x : ending) {
            sum = (sum + powMod(x.second, scheme[i])) % MOD;
        }

        ans = ans * sum % MOD;
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
    // clock_t start = clock();

    // ll a; cin >> a;
    // while (a--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}
