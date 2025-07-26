#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


vector <ll> x = {0, 1, 2, 3, 4, 5, 0, 1, 3, 4, 6, 7};
vector <ll> y = {3, 4, 5, 6, 7, 8, 1, 2, 4, 5, 7, 8};
unordered_map <string, ll> step; // How many step do we need to reach each grid (faster than map)
string grid, target = "123456789";

void generateSwap() {
    queue <string> q; q.push(target);
    step[target] = 1; // 123456789 is already correct

    while (!q.empty()) {
        string curr = q.front(); q.pop();
        ll tmp = step[curr]; // Step to reach the string before change
        // Total 12 swap x with y (x, y is two adjacent cell)
        for (ll i = 0; i < 12; i++) {
            swap(curr[x[i]], curr[y[i]]); // Each case
            if (!step[curr]) {
                step[curr] = tmp + 1;
                q.push(curr);
            }
            swap(curr[x[i]], curr[y[i]]); // Backtrack to the previous
        }
    }
}

void solve() {
    generateSwap();

    for (ll i = 1; i <= 9; i++) {
        string s; cin >> s;
        grid += s;
    }

    cout << step[grid]-1 << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0);

    // ll t; cin >> t;
    // while (t--)
    solve();
}