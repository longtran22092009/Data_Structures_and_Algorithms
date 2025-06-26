#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

set <int> findDivisors(int n) {
    set <int> res;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            res.insert(i);
            res.insert(n/i);
        }
    }
    return res;
}

void solve() {
    int n; cin >> n;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    // Minimum number of modifications x is one of the divisors of total ai
    // From total we can divide into some log with value of x
    set <int> divisors = findDivisors(accumulate(a.begin(), a.end(), 0));

    int ans = INT32_MAX;
    for (auto &x : divisors) {
        // cout << x << " ";
        int curr = 0, cnt = 0;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            while (curr + a[i] < x) {
                curr += a[i];
                ++cnt;
                ++i;
            }
            curr += a[i];

            if (curr > x) { 
                ok = false; 
                break; 
            }
            else curr = 0;
        }

        if (ok) ans = min(ans, cnt);
    }

    if (ans == INT32_MAX) cout << "0\n";
    else cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll t; cin >> t;
    while (t--)
        solve();
}
