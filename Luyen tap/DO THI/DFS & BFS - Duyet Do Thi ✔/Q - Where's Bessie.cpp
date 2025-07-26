#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "where.in"
#define OUT "where.out"
#define DEBUG "debug.out"


struct Rect {
    int tx, ty, bx, by;
};

const int mxN = 25, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;

vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
vector<Rect> rect;
int n;
char grid[mxN][mxN];
bool vis[mxN][mxN];

void bfs(int x, int y, int lx, int ly, int rx, int ry, char color) {
    queue <pair <int, int>> q; q.push({x, y});
    vis[x][y] = true;

    while (!q.empty()) {
        int currx = q.front().first, curry = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = currx + dx[i], ny = curry + dy[i];
            if (nx < lx || nx > rx || ny < ly || ny > ry) continue;
            if (vis[nx][ny] || grid[nx][ny] != color) continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

bool isContained(Rect &a, Rect &b) {
    return b.tx >= a.tx && b.ty >= a.ty && b.bx <= a.bx && b.by <= a.by;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> grid[i][j];
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            for (int c = a; c <= n; c++) {
                for (int d = b; d <= n; d++) {
                    memset(vis, false, sizeof(vis));
                    map <char, int> comps;

                    for (int i = a; i <= c; i++) {
                        for (int j = b; j <= d; j++) {
                            if (!vis[i][j]) {
                                bfs(i, j, a, b, c, d, grid[i][j]);
                                ++comps[grid[i][j]];
                            }
                        }
                    }

                    int one = 0, multi = 0;
                    if (comps.size() == 2) {
                        for (auto &x : comps) {
                            if (x.second == 1) ++one;
                            else ++multi;
                        }
                    }
                    if (one == 1 && multi == 1) rect.push_back({a, b, c, d});
                }
            }
        }
    }

    int m = (int) rect.size();
    vector <bool> valid(m, true);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            // If rect j is contained by rect i
            if (i != j && isContained(rect[i], rect[j])) valid[j] = false;
        }
    }

    int ans = count(valid.begin(), valid.end(), true);
    cout << ans << endl;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios::sync_with_stdio(false); cin.tie(0);

    // ll t; cin >> t;
    // while (t--)
    solve();
}
