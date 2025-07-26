#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "countcross.in"
#define OUT "countcross.out"
#define DEBUG "debug.out"

const int mxN = 105, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;

vector <int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1}, comps;
int n, k, R;
bool isRoad[mxN][mxN][4], vis[mxN][mxN], cow[mxN][mxN]; 
// road[x][y][dir]
// 0: up, 1: down, 2: left, 3: right

void bfs(int i, int j) {
    int cnt = 0;
    queue <pair <int, int>> q; q.push({i, j});
    if (cow[i][j]) ++cnt;
    vis[i][j] = true;
    
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            // Is out of bound
            if (nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny]) continue;
            // Is there a road
            if (isRoad[x][y][d] || isRoad[nx][ny][1^d]) continue;

            if (cow[nx][ny]) ++cnt;
            cerr << nx << " " << ny << endl;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    comps.push_back(cnt);
}

void solve() {
    cin >> n >> k >> R;

    for (int i = 1; i <= R; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        // Left - right
        if (b == d) {
            if (a < c) {
                isRoad[a][b][1] = true;
                isRoad[c][d][0] = true;
            }
            else{
                isRoad[a][b][0] = true;
                isRoad[c][d][1] = true;
            }
        }
        // Up - down
        if (a == c) {
            if (b < d) {
                isRoad[a][b][3] = true;
                isRoad[c][d][2] = true;
            }
            else{
                isRoad[a][b][2] = true;
                isRoad[c][d][3] = true;
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        cow[x][y] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) bfs(i, j);
        }
    }

    int totalCow = k, ans = 0;
    for (auto &x : comps) {
        ans += x * (totalCow - x);
        totalCow -= x;
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