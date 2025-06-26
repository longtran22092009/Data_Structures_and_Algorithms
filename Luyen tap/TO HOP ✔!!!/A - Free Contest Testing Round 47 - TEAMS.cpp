#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll a, b, c; cin >> a >> b >> c;

    ll maxTeam = min(a/2, b);

    ll remain = a + b - maxTeam*3;

    if (remain < c) {
        c -= remain;
        maxTeam -= (c-1)/3 + 1;

    }
    cout << maxTeam << endl;
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
