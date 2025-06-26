#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

ll f(ll n,ll k) {
    if (n == 1) return 1;
    if (k <= (n+1)/2) {
        if (2 * k > n) return 2 * k % n; // The first was removed by the last 
        return 2 * k;
    }

    ll x = f(n/2, k - (n+1)/2);
    if(n % 2 != 0) return 2 * x + 1;
    return 2 * x - 1;
}

void solve() {
    ll n, k; cin >> n >> k;
    cout << f(n, k) << endl;
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
