#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "fortmoo.in"
#define OUT "fortmoo.out"
#define DEBUG "debug.out"

const int mxN = 205, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18, MOD = (ll) 1e9+7;

void solve() {
    int n, m; cin >> n >> m;

    vector <vector <bool>> grid(n+1, vector <bool>(m+1));
    vector <vector <int>> pre(n+1, vector <int>(m+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch; cin >> ch;
            grid[i][j] = (ch == 'X');

            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + grid[i][j];
        }
    }

    int ans = 0;
    for (int c1 = 1; c1 <= m; c1++) {
        for (int c2 = 1; c2 <= m; c2++) {
            int prev = -1;

            for (int r = 1; r <= n; r++) {
                bool isEmpty = (pre[r][c2] - pre[r-1][c2] - pre[r][c1-1] + pre[r-1][c1-1] == 0);
                
                if (isEmpty) {
                    ans = max(ans, c2 - c1 + 1);

                    if (prev != -1) ans = max(ans, (r - prev + 1) * (c2 - c1 + 1));
                    else prev = r;
                }

                if (grid[r][c1] || grid[r][c2]) prev = -1; // col c1/c2 at row r is X
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    // ll t; cin >> t;
    // while (t--)
    solve();
}