#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    a * b = 0 khi b = 0
    a * b = 2 * a * b/2 khi b chẵn và > 0
    a * b = 2 * a * (b-1)/2 + a khi b lẻ và > 0
*/


const ll MOD = (ll) 1e9 + 7;

long long binmul(long long a, long long b) {
    if (!b) return 0;
    long long x = binmul(a, b / 2);
    if (b % 2 == 0)
        return 2 * x % MOD;
    else
        return (2 * x + a) % MOD;
}

void solve() {
    cout << __cplusplus;
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
