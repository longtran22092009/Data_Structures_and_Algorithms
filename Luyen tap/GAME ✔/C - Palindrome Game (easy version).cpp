#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    ll zeros = 0;
    for (auto &ch : s) {
        if (ch == '0') ++zeros;
    }

    if (zeros % 2 == 0 || zeros == 1) cout << "BOB\n";
    else cout << "ALICE\n";
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
