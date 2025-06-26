#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    vector <vector <ll>> sudoku(9, vector <ll>(9));
    for (ll i = 0; i < 9; i++) {
        ll s; cin >> s;

        for (ll j = 8; j >= 0; j--) {
            sudoku[i][j] = s%10;
            s /= 10;
        }
    }

    for (ll i = 0; i < 9; i++) {
        for (ll j = i/3; j < 9; j+=3) {
            if (sudoku[i][j] == 9) sudoku[i][j]--;
            else sudoku[i][j]++;

            ++i;
        }
        --i;
    }

    for (auto &x : sudoku) {
        for (auto &y : x) cout << y;
        cout << endl;
    }
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
