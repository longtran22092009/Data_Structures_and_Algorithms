#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const ll MOD = (ll) 1e9 + 7;

ll powMod(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;

    while (b) {
        if (b % 2 == 1) {
            res *= a;
            res %= m;
        }

        a *= a;
        a %= m;
        b /= 2;
    }

    return res;
}

ll inversion(ll a, ll m) {
    return powMod(a, m-2, m);
}

void solve() {
    ll n; cin >> n;

    ll sum = n*(n+1)/2; 
    if (sum % 2 != 0) {
        cout << "0\n";
        return;
    }

    ll eachSide = sum/2;
    vector <ll> dp(sum+1, 0);
    dp[0] = 1;

    // 1,2,...,n-1 not 1,2,...,n
    // Let n in the one set so we just need to count number of set make from 1,2,...,n-1
    // The other set have same sum will automatically obtain n
    for (ll i = 1; i <= n; i++) {
        for (ll j = sum; j >= 1; j--) {
            if (j-i >= 0) dp[j] = (dp[j] + dp[j-i]) % MOD; 
        }
    }

    // Inverse modular
    cout << dp[eachSide] % MOD * inversion(2, MOD) % MOD << endl;

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