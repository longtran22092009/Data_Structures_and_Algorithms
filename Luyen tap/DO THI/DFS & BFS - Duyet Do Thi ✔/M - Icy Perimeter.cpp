#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "perimeter.in"
#define OUT "perimeter.out"


const int mxN = 1005;
int n, S = 0, P = 0, s = 0, p = 0;
vector <int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
bool vis[mxN][mxN];
char board[mxN][mxN];

void bfs(int x, int y) {
    queue <pair <int, int>> q; q.push({x, y});
    vis[x][y] = true;
    ++s;

    int blocked = 0;
    for (int i = 0; i < 4; i++) blocked += vis[x + dx[i]][y + dy[i]];
    p += 4 - 2 * blocked;

    while (!q.empty()) {
        pair <int, int> u = q.front(); q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = u.first + dx[i];
            int ny = u.second + dy[i];
            
            if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] != '#' || vis[nx][ny]) continue;
            
            int blocked = 0;
            for (int i = 0; i < 4; i++) blocked += vis[nx + dx[i]][ny + dy[i]];
            p += 4 - 2 * blocked;

            vis[nx][ny] = true;
            q.push({nx, ny});
            ++s;
        }
    }
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> board[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] != '#' || vis[i][j]) continue;

            s = 0, p = 0;
            bfs(i, j);
            if (s >= S) {
                P = (s == S)? min(P, p) : p;
                S = s;
            }
        }
    }

    cout << S << " " << P << endl;
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