#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    ## Pseudocode ##

    ConnectedComponent() {
        // Khởi tạo số thành phần liên thông bằng 0
        cnt = 0;

        // Lặp
        for (ll i = 1; i <= n; i++) {
            if (!visited[i]) {
                ++cnt;
                DFS(i); // BFS(i)
            }
        }

        return cnt;
    }
*/

/*
    VD: 10 8
        1 2
        2 3
        2 4
        3 6
        3 7
        5 8
        6 7
        8 9

    =>  3
*/


ll n, m;
vector <bool> visited;
vector <vector <ll>> adj;

void DFS(ll u) {
    cout << u << " ";
    visited[u] = 1;

    for (auto &v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

void BFS(ll u) {
    queue <ll> q;
    q.push(u);
    visited[u] = 1;

    while (!q.empty()) {
        ll v = q.front(); 
        q.pop();

        cout << v << " ";

        for (auto &x : adj[v]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}

void connectedCoponent() {
    ll cnt = 0;

    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            ++cnt;

            cout << "Các đỉnh thuộc thành phần liên thông thứ " << cnt << ": " << endl;
            DFS(i);
            //BFS(i);
            cout << endl;
        }
    }

    cout << "Số thành phần liên thông của đồ thị: " << cnt;
}

void solve() {
    cin >> n >> m;

    visited.resize(n+1, 0);
    adj.resize(n+1);

    // Edge list to Adjacency list
    for (ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    connectedCoponent();
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    solve();
}
