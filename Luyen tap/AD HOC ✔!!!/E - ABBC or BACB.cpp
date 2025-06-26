#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    string s; cin >> s;
    ll n = (ll) s.size();

    ll cnt = 0, B = 0;
    vector <ll> val;

    for (ll i = 0; i < n; i++) {
        while (s[i] == 'A') {
            ++cnt;
            ++i;
        }

        if (s[i] == 'B') ++B;
        val.push_back(cnt);
        cnt = 0;
    }
    sort(val.begin(), val.end(), greater<ll>());

    ll ans = 0;
    for (ll i = 0; i < B; i++) ans += val[i];

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
