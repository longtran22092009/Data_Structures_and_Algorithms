#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


ll n, m; 
vector <vector <char>> board(1001, vector <char>(1001));
vector <vector <bool>> vis(1001, vector <bool>(1001, 0));
vector <vector <char>> previous(1001, vector <char>(1001));

vector <ll> di = {-1, 0, 0, 1};
vector <ll> dj = {0, -1, 1, 0};
string dir = "ULRD";

void bfs(ll i, ll j) {
    queue <pair <ll, ll>> q; q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty()) {
        pair <ll, ll> u = q.front(); q.pop();

        for (ll k = 0; k < 4; k++) {
            pair <ll, ll> v = {u.first + di[k], u.second + dj[k]};

            if (v.first < 1 || v.first > n || v.second < 1 || v.second > m) continue;
            if (board[v.first][v.second] == '#') continue;
            if (vis[v.first][v.second]) continue;

            vis[v.first][v.second] = 1;
            previous[v.first][v.second] = k;
            q.push(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    
    pair <ll, ll> s, t;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'A') {
                s = {i, j};
            }
            if (board[i][j] == 'B') {
                t = {i, j};
            }
        }
    }

    bfs(s.first, s.second);

    if (!vis[t.first][t.second]) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    
    vector <ll> path;
    while (t != s) {
        ll last = previous[t.first][t.second];
        path.push_back(last);

        t = {t.first - di[last], t.second - dj[last]};
    }
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (auto &x : path) cout << dir[x];
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}
