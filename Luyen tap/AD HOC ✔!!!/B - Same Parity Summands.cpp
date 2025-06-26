#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n, k; cin >> n >> k;

    ll allOdd = n - k + 1;
    if (allOdd > 0 && allOdd % 2 == 1) {
        cout << "YES" << endl;

        for (ll i = 0; i < k-1; i++) {
            cout << 1 << " ";
        }
        cout << allOdd << endl;
        return;
    }

    ll allEven = n - 2*(k-1);
    if (allEven > 0 && allEven % 2 == 0) {
        cout << "YES" << endl;

        for (ll i = 0; i < k-1; i++) {
            cout << 2 << " ";
        }
        cout << allEven << endl;
        return;
    }

    cout << "NO" << endl;
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
