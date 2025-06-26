#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


// DFS: Depth First Search (Đệ quy)
// Thuật toán tìm kiếm theo chiều sâu:
// Ưu tiên duyệt xuống sâu nhất có thể trước khi quay lại
// * Kiểm tra tính liên thông của đồ thị *

/*
    ## Pseudocode ##

    // Bắt đầu duyệt từ đỉnh u
    DFS (u) {
        // Đi qua (thăm) đỉnh u
        visited[u] = true; // Đánh dấu đỉnh u đã đi qua (thăm)

        // Duyệt qua các đỉnh kề với đỉnh u
        for (v : adj[u]) {
            // Nếu chưa đi qua (thăm) đỉnh v
            if (!visited[v]) {
                DFS(v);
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
    VD: 9 9
        1 2
        1 3
        1 5
        2 4
        3 6
        3 7
        3 9
        5 8
        8 9

    =>  1 2 4 3 6 7 9 8 5

    VD: 9 10
        1 2
        1 3
        1 5
        2 4
        3 6
        3 7
        5 8
        6 7
        8 9
        9 3

    =>  1 2 4 3 6 7 5 8 9 
*/

vector <bool> visited;
vector <vector <ll>> adj;

void DFS(ll u) {
    cout << u << " ";
    visited[u] = 1;

    for (auto &v : adj[u]) {
        if (!visited[v]) DFS(v);
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

    DFS(1);
}


/*
    ## Khi duyệt DFS sẽ tạo thành một cây (tree):
        Tree Edge: Là cạnh mà ta đi từ một đỉnh qua (thăm) một đỉnh mới (đỉnh kề)
        Back Edge: Cạnh ngược là cạnh đi từ nốt con đến nốt cha (descendant to ancestor)
        Forward Edge: Cạnh tới là cạnh đi từ nốt cha đến nốt con (không phải đỉnh kề) (khác tree edge)
        Cross Edge: Cạnh vòng là cạnh nối hai đỉnh không có quan hệ họ hàng (không có đường đi)
*/


int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    solve();
}
