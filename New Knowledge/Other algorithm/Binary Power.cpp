#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


// Tính a^n
ll binpow(ll a, ll n) {
    ll res = 1;

    while (n) {
        if (n % 2 == 1) {
            res *= a;
        }

        a *= a;
        n /= 2;
    }

    return res;
}

void solve() {
    ll a, n; cin >> a >> n;

    cout << binpow(a, n) << endl;
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