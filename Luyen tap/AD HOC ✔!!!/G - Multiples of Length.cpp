#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;

    vector <ll> a(n);
    for (auto &x : a) cin >> x;

    if (n == 1) {
        cout << "1 1\n0\n1 1 \n0\n1 1\n" << -a[0] << endl;
        return;
    }

    cout << "1 1\n" << -a[0] << endl;

    cout << "2 " << n << endl;
    for (ll i = 1; i < n; i++) {
        cout << 1ll * (n-1) * a[i] << " ";
    }
    cout << endl;

    cout << "1 " << n << endl << "0 ";
    for (ll i = 1; i < n; i++) cout << 1ll * -n * a[i] << " ";
    cout << endl;
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
