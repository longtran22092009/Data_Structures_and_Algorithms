#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


// BFS: Breadth First Search (Hàng đợi)
// Thuật toán tìm kiếm theo chiều sâu: Ưu tiên chiều rộng hơn là chiều sâu
// Thuật toán sẽ tìm kiếm xung quanh để mở rộng trước khi xuống sâu hơn
// * Tìm đường đi ngắn nhất trong đồ thị không có trọng số *

/*
    ## Pseudocode ##

    // Bắt đầu duyệt từ đỉnh u
    BFS (u) {
        // Step 1: Khởi tạo
        queue = {}; // Tạo một hàng đợi rỗng
        push(queue, u); // Đẩy đỉnh u vào hàng đợi
        visited[u] = true; // Đánh dấu đỉnh u đã được đi qua (thăm)

        // Step 2: Lặp khi hàng đợi vẫn còn phần tử
        while (queue != {}) {
            v = queue.front(); // Lấy đỉnh v là đỉnh ở đầu hàng đợi
            queue.pop(); // Xóa đỉnh vừa lấy ra khỏi hàng đợi

            // Duyệt các đỉnh kề với v mà chưa được đi qua (thăm) và đẩy vào hàng đợi
            for (x : adj[v]) {
                // Nếu chưa đi qua (thăm) đỉnh x
                if (!visited[x]) {
                    push(queue, x);
                    visited[x] = true;
                }
            }
        }
    }

    ## Độ phức tạp (phụ thuộc vào cách biểu diễn đồ thị) ##
    Đồ thị G = <V, E>
    Ma trận kề: O(V * V)
    Danh sách cạnh: O(V * E)
    Danh sách kề: O(V + E)
*/

/*
    # Đồ thị vô hướng
    VD: 10 11
        1 2
        1 3
        1 5
        1 10
        2 4
        3 6
        3 7
        3 9
        5 8
        6 7
        8 9

    =>  1 2 3 5 10 4 6 7 9 8 

    # Đồ thị có hướng
    VD: 10 11
        1 2
        1 3
        1 10
        2 4
        3 5
        3 6
        5 8
        5 10
        6 7
        7 3
        8 9

    =>  1 2 3 10 4 5 6 8 7 9 
*/

vector <bool> visited;
vector <vector <ll>> adj;

void BFS(ll u) {
    // Khởi tạo
    queue <ll> q;
    q.push(u);
    visited[u] = 1;

    // Duyệt khi hàng đợi vẫn còn phần tử
    while (!q.empty()) {
        ll v = q.front();
        q.pop();

        cout << v << " ";
        
        for (auto x : adj[v]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}

void solve() {
    // n là số đỉnh, m là số cạnh
    ll n, m; cin >> n >> m;

    visited.resize(n+1, 0);
    adj.resize(n+1);

    for (ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        
        adj[x].push_back(y);
        // Nếu đồ thị có hướng thì bỏ dòng dưới này (Cách chuyển thành danh sách kề cho đồ thị có hướng)
        adj[y].push_back(x);
    }

    // for (ll i = 1; i <= n; i++) {
    //     for (auto &x : adj[i]) cout << x << " ";
    //     cout << endl;
    // }

    BFS(1);
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    solve();
}
