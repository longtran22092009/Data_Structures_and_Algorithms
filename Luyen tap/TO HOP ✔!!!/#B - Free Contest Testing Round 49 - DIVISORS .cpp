#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

void pt(ll num, map <ll, ll> &exp) {
    for (ll i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            ll cnt = 0;
            while (num % i == 0) {
                ++cnt;
                num /= i;
            }

            exp[i] += cnt;
        }
    }

    if (num != 1) exp[num]++;
}

void solve() {
    ll n, k;

    while (cin >> n >> k) {
        map <ll, ll> exp1, exp2, res_exp;

        // Factorize(n!)
        for (ll i = 1; i <= n; i++) {
            pt(i, exp1);
        }        
        // Factorize(k!)
        for (ll i = 1; i <= k; i++) {
            pt(i, exp2);
        }
        // Factorize(n-k!)
        for (ll i = 1; i <= n-k; i++) {
            pt(i, exp2);
        }

        ll ans = 1;
        for (auto &e : exp1) {
            ll res_e = e.second - exp2[e.first];

            ans *= res_e + 1;
        }
        
        cout << ans << endl;
    }
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
