#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

void solve() {
    ll n; cin >> n;

    vector <ll> a(n+1);
    for (ll i = 1; i <= n; i++) cin >> a[i];

    ll ans = a[1];
    for (ll i = 2; i <= n; i++) {
        if(a[i] == 0) continue;

        ll cnt = 0;
        while (i <= n && a[i] == 1) {
            ++cnt; ++i;
        }
        --i;

        // We will kill 2 bosses with hard 1 and our friend with just 1 => total 3 in turn
        ans += cnt/3;
    }

    cout << ans << endl;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll t; cin >> t;
    while (t--)
        solve();
}
