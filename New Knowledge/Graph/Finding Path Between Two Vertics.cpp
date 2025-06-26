#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


// Tìm đường đi giữa 2 đỉnh trong đồ thị vô hướng / có hướng (không có trọng số)
// Sử dụng dfs / bfs kết hợp với mảng parent để truy vết đường đi từ đỉnh A đến đỉnh B

/* 
    Nếu cho q truy vấn thì sử dụng một cái map or sth 
    để lưu lại các đỉnh thuộc thành phần liên thông thứ mấy
    để khi kiểm tra chỉ cần kiểm tra nếu 2 đỉnh cùng thành phần liên thông không
    nếu cùng thì có đường đi và ngược lại
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
        1 7

    =>  Đường đi từ 1 đến 7: 1 2 3 6 7 (DFS)
        Đường đi từ 1 đến 7: 1 2 3 7 (BFS)

    VD: 10 8
        1 2
        2 3
        2 4
        3 6
        3 7
        5 8
        6 7
        8 9
        1 10

    =>  Không có đường đi từ 1 đến 10
*/


// s: đỉnh bắt đầu, t: đỉnh kết thúc
ll n, m, s, t;
vector <bool> visited;
vector <vector <ll>> adj;
vector <ll> parent;

void DFS(ll u) {
    visited[u] = 1;

    for (auto &v : adj[u]) {
        if (!visited[v]) {
            // Lưu lại nốt cha của v
            parent[v] = u;
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

        for (auto &x : adj[v]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = 1;
                parent[x] = v;
            }
        }
    }
}

void findPath(ll s, ll t) {
    // DFS(s);
    BFS(s);

    if (!visited[t]) {
        cout << "Không có đường đi từ " << s << " đến " << t << endl;
    }

    else {
        cout << "Đường đi từ " << s << " đến " << t << ": ";

        // Truy vết lại đường đi
        vector <ll> path;

        while (t != s) {
            path.push_back(t);
            t = parent[t];
        }
        
        path.push_back(s);
        reverse(path.begin(), path.end());
        
        for (auto &x : path) cout << x << " ";
    }
}

void solve() {
    cin >> n >> m;

    visited.resize(n+1, 0);
    adj.resize(n+1);
    parent.resize(n+1, 0);

    // Edge list to Adjacency list
    for (ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cin >> s >> t;
    findPath(s, t);
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    solve();
}
