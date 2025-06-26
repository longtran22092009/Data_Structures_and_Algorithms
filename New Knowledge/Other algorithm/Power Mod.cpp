#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


// Tính a^b^c mod m:
// a^(m-1) = 1 mod m
// => a^ (b^c mod m-1) mod m

// Tính lũy thừa mod m (a^b % m)
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

void solve() {
    ll a, b; cin >> a >> b;
    powMod(a, b, 1000000007);
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
