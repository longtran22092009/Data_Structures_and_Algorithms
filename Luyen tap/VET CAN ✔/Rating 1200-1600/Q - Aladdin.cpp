#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 205, INF = (int) 1e9+5;
int n; 
int grid[mxN][mxN], a[mxN][mxN];
bool ok = false;

void backtrack(int k) {
    if (k == n+1) {
        ok = true;
        for (int ii = 1; ii <= n; ii++) {
            for (int jj = 1; jj <= n; jj++) cout << a[ii][jj] << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }
    
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            bool valid = true;
            a[1][k] = i;
            a[k][1] = j;
            // Vertical
            for (int x = 2; x <= k-1; x++) { // Do not change the lower corner
                a[x][k] = grid[x-1][k-1] - (a[x-1][k] + a[x][k-1] + a[x-1][k-1]);
                if (a[x][k] < 0 || a[x][k] > 1) {
                    valid = false;
                    break;
                }
                // cout << "Vertical, x = " << x << ", total = " << grid[x-1][k-1] << ": " << a[x][k] << endl; 
            }
            
            // Horizontal
            for (int x = 2; x <= k; x++) {
                a[k][x] = grid[k-1][x-1] - (a[k-1][x] + a[k][x-1] + a[k-1][x-1]);
                if (a[k][x] < 0 || a[k][x] > 1) {
                    valid = false;
                    break;
                }
                // cout << "Horizontal, x = " << x << ", total = " << grid[x-1][k-1] << ": " << a[k][x] << endl; 
            }

            if (valid) backtrack(k+1);
            if (ok) return; // Found the answer
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        for (int j = 1; j <= n-1; j++) cin >> grid[i][j];
    }

    memset(a, 0, sizeof(a));
    a[1][1] = 0;
    backtrack(2);

    if (!ok) { // a[1][1] = 0 is wrong
        memset(a, 0, sizeof(a));
        a[1][1] = 1;
        backtrack(2);
    }

    if (!ok) cout << "No solution\n";
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
