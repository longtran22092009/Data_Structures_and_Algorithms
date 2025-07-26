#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    
    vector <ll> v(n+1), pre(n+1, v[1]);
    for (int i = 1; i <= n; i++) cin >> v[i];
    pre[1] = v[1];
    for (int i = 2; i <= n; i++) pre[i] = pre[i-1] + v[i];
    
    multiset <ll> curr;
    ll ans = (ll) -1e18;
    // Maximum sum in range [a, b] => pre[i] - pre[j]
    // with (j > i-b) pre[j] is minimum
    for (int i = a; i <= n; i++) {
        curr.insert(pre[i-a]);
        // i in range [i-b, i-a]
        if (i-b-1 >= 0) curr.erase(curr.find(pre[i-b-1]));

        ans = max(ans, pre[i] - *curr.begin());
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