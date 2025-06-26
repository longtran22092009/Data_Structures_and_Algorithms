#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 2000005, INF = (int) 1e9+5;
ll n, L, R; 
vector <ll> a(mxN);

ll cal(ll limit) {
    ll l = 0, res = 0;
    map <ll, ll> freq;
    for (ll r = 0; r < n; r++) {
        freq[a[r]]++;
        while (l <= r && (ll) freq.size() > limit) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) freq.erase(a[l]);
            ++l;
        }
        res += r-l+1;
    }
    return res;
}

void solve() {
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = cal(R) - cal(L-1);
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