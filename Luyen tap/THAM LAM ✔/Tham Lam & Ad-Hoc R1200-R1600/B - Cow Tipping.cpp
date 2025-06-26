#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "cowtip.in"
#define OUT "cowtip.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;

    int a[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char ch; cin >> ch;
            a[i][j] = ch - '0';
        }
    }

    int cnt = 0;
    for (int corner = n; corner >= 1; corner--) {
        // Vertical
        for (int k = corner; k >= 1; k--) {
            if (a[corner][k]) {
                // Flip the square with upper-left corner
                for (int i = 1; i <= corner; i++) {
                    for (int j = 1; j <= k; j++) {
                        a[i][j] ^= 1;
                    }
                }
                ++cnt;
            }
        }
        // Horizontal
        for (int k = corner; k >= 1; k--) {
            if (a[k][corner]) {
                // Flip the square with upper-left corner
                for (int i = 1; i <= k; i++) {
                    for (int j = 1; j <= corner; j++) {
                        a[i][j] ^= 1;
                    }
                }
                ++cnt;
            }
        }
    }

    cout << cnt << endl;
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
