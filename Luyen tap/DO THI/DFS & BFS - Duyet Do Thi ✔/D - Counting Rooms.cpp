#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


ll n, m; 
vector <vector <char>> board(1001, vector <char>(1001));
vector <ll> di = {-1, 0, 0, 1}, dj = {0, -1, 1, 0};

void dfs(ll i, ll j) {
    board[i][j] = '#';
    // i, j => i-1/i+1, j-1/j+1
    for (ll k = 0; k < 4; k++) {
        ll i1 = i+di[k], j1 = j+dj[k];

        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && board[i1][j1] == '.') {
            dfs(i1, j1);
        }
    }
}

void solve() {
    cin >> n >> m;
    
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (board[i][j] == '.') {
                dfs(i, j);
                ++cnt;
            }
        }
    }

    cout << cnt;
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
