#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    // n is even
    // Coordinate look like: (x, y)
    ll n; cin >> n;

    /*
    VD: n = 4
    5        ##
    4       ###
    3      ###
    2     ###
    1    ###
    0    ##
         012345        
    */

    cout << n*3 + 4 << endl;
    cout << "0 0\n0 1\n";

    for (ll i = 1; i <= n; i++) {
        for (ll j = i; j < i+3; j++) {
            cout << i << " " << j-1 << endl;
        }
    }

    cout << n+1 << " " << n << endl;
    cout << n+1 << " " << n+1 << endl;
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
