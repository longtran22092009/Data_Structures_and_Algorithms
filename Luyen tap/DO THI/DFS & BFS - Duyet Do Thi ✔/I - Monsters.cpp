#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

const ll mxN = 1005;
ll n, m, cnt = 0;
vector <ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
string dir = "UDLR";
vector <vector <char>> grid(mxN, vector <char>(mxN));
vector <vector <ll>> moves(mxN, vector <ll>(mxN, -1));
vector <vector <pair <ll, ll>>> par(mxN, vector <pair <ll, ll>>(mxN, {-1, -1}));
bool vis[mxN][mxN];

vector <vector <ll>> dis1(mxN, vector <ll>(mxN, LONG_LONG_MAX)); // For monsters
vector <vector <ll>> dis2(mxN, vector <ll>(mxN, LONG_LONG_MAX)); // For us
vector <pair <ll, ll>> mons;
pair <ll, ll> us;


// Bfs to find the shortest dis from mons to each cell 
void bfs1() {
    queue <pair <int, int>> q;

    for (auto &m : mons) {
        vis[m.first][m.second] = true;
        dis1[m.first][m.second] = 0;
        q.push(m);
    }

    while (!q.empty()) {
        pair <ll, ll> u = q.front(); q.pop();

        for (ll i = 0; i < 4; i++) {
            ll nx = u.first + dx[i], ny = u.second + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || grid[nx][ny] == '#') continue;
            dis1[nx][ny] = min(dis1[nx][ny], dis1[u.first][u.second] + 1);
            
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

// Bfs to find the shortest dis from us to each cell 
void bfs2() {
    memset(vis, false, sizeof(vis));
    queue <pair <int, int>> q;

    vis[us.first][us.second] = true;
    dis2[us.first][us.second] = 0;
    q.push({us.first, us.second});

    while (!q.empty()) {
        pair <ll, ll> u = q.front(); q.pop();

        // Backtrack the path
        if (u.first == 1 || u.first == n || u.second == 1 || u.second == m) {
            string path;
            pair <ll, ll> curr = u;

            while (curr != us) {
                path += dir[moves[curr.first][curr.second]];
                curr = par[curr.first][curr.second];
            }
            reverse(path.begin(), path.end());

            cout << "YES\n" << path.size() << endl;
            cout << path << endl;
            return;
        }

        for (ll i = 0; i < 4; i++) {
            ll nx = u.first + dx[i], ny = u.second + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || grid[nx][ny] == '#') continue;
            dis2[nx][ny] = min(dis2[nx][ny], dis2[u.first][u.second] + 1);

            if (vis[nx][ny] || dis1[nx][ny] <= dis2[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});

            par[nx][ny] = u;
            moves[nx][ny] = i;
        }
    }

    cout << "NO\n";
}

void solve() {
    cin >> n >> m;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') mons.push_back({i, j});
            if (grid[i][j] == 'A') us = {i, j};
        }
    }

    bfs1();
    bfs2();
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