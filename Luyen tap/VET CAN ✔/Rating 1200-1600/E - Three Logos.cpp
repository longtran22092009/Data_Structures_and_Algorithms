#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


struct Sqr {
    int x, y;
    int area() { return x*y; }
};

const int mxN = 105, INF = (int) 1e9+5;
int S, edge, grid[mxN][mxN];
vector <Sqr> a(4);
bool found = false;

void build(int k) {
    if (k == 4) {
        bool ok = true;
        for (int i = 1; i <= edge; i++) {
            for (int j = 1; j <= edge; j++) {
                if (grid[i][j] == 0) ok = false;
            }
        }

        found = ok;
        return;
    }
    
    for (int i = 1; i <= edge; i++) {
        for (int j = 1; j <= edge; j++) {
            if (i + a[k].x - 1  <= edge && j + a[k].y - 1 <= edge) { // Type 1:
                // Is there enough space to put a logo
                bool isEmpty = true;
                for (int ii = i; ii <= i + a[k].x - 1; ii++) {
                    for (int jj = j; jj <= j + a[k].y - 1; jj++) {
                        if (grid[ii][jj] != 0) isEmpty = false;
                    }
                }
                if (!isEmpty) continue; // No
                
                // Yes
                for (int ii = i; ii <= i + a[k].x - 1; ii++) {
                    for (int jj = j; jj <= j + a[k].y - 1; jj++) {
                        grid[ii][jj] = k;
                    }
                }
                
                build(k+1);
                if (found) return;
                
                // Backtrack
                for (int ii = i; ii <= i + a[k].x - 1; ii++) {
                    for (int jj = j; jj <= j + a[k].y - 1; jj++) {
                        grid[ii][jj] = 0;
                    }
                }
            }

            if (i + a[k].y - 1  <= edge && j + a[k].x - 1 <= edge) { // Type 2:
                // Is there enough space to put a logo
                bool isEmpty = true;
                for (int ii = i; ii <= i + a[k].y - 1; ii++) {
                    for (int jj = j; jj <= j + a[k].x - 1; jj++) {
                        if (grid[ii][jj] != 0) isEmpty = false;
                    }
                }
                if (!isEmpty) continue; // No
                
                // Yes
                for (int ii = i; ii <= i + a[k].y - 1; ii++) {
                    for (int jj = j; jj <= j + a[k].x - 1; jj++) {
                        grid[ii][jj] = k;
                    }
                }
                
                build(k+1);
                if (found) return;
                
                // Backtrack
                for (int ii = i; ii <= i + a[k].y - 1; ii++) {
                    for (int jj = j; jj <= j + a[k].x - 1; jj++) {
                        grid[ii][jj] = 0;
                    }
                }
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= 3; i++) cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= 3; i++) {
        if (a[i].x < a[i].y) swap(a[i].x, a[i].y);
    }

    S = a[1].area() + a[2].area() + a[3].area();
    edge = sqrt(S);

    if (edge * edge != S) {
        cout << "-1\n";
        return;
    }

    build(1);
    if (found) {
        cout << edge << endl;
        for (int i = 1; i <= edge; i++) {
            for (int j = 1; j <= edge; j++) {
                cout << (char) (grid[i][j] + 64);
            }
            cout << endl;
        }
    }
    else cout << "-1\n";
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
