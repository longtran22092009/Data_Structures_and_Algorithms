#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;

    if (n <= 3) {
        cout << "-1\n";
        return;
    }

    for (ll i = ((n % 2 == 0)? n-1 : n); i >= 1; i -= 2) cout << i << " ";
    cout << "4 2 ";
    for (ll i = 6; i <= n; i += 2) cout << i << " ";

    cout << endl;
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
