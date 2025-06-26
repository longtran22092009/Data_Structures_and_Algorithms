#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    ## Tìm chu trình trên đồ thị vô hướng ##
        Sử dụng dfs -> bool
        nếu từ một đỉnh u duyệt thấy có đỉnh v đã được thăm -> có đường đi từ v tới u
        và v không phải là nốt cha trực tiếp của u thì (u,v) là cạnh ngược
        hay có nghĩa đó là 1 chu trình

    Pseudocode:
    bool dfs(ll u, ll par) {
        vis[u] = true;

        for (auto &v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, u)) return true;
            }
            else if (v != par) return true;
        }

        return false;
    }

    VD: 6 6 => YES,  VD: 6 5 => NO
        1 2              1 2
        2 4              2 4
        2 3              2 3
        3 5              3 5
        3 6              5 6
        5 6

    ## Tìm chu trình trên đồ thị có hướng ##
        Sử dụng dfs -> bool kết hợp mảng color (kiểm tra đã hoàn thành dfs chưa)
        nếu từ một đỉnh u duyệt thấy có đỉnh v đã được thăm -> có đường đi từ v tới u
        và v không phải là nốt cha trực tiếp của u thì (v, u) là cạnh ngược
        hay có nghĩa đó là 1 chu trình

    Pseudocode:
    # 0: Trắng (chưa thăm), 1: Xám (Đang thăm), 2: Đen (Đã thăm xong)

    bool dfs(ll u) {
        color[u] = 1;

        for (auto &v : adj[u]) {
            if (color[v] == 0) {
                par[v] = u;
                if (dfs(v)) return true;
            }
            else if (color[v] == 1) return true; // Vẫn còn đỉnh kề chưa thăm => có đỉnh ngược (v, u)
        }
        color[u] = 2; // Đã thăm xong các đỉnh kề
        return false;
    }

    VD: 7 7 => YES,  VD: 7 7 => NO
        1 2              1 2
        1 5              1 5
        2 3              2 3
        3 6              3 6
        4 2              4 2
        6 7              6 7
        7 3              3 7
*/


int n, m;
vector <vector <int>> adj;
vector <int> color, par;
bool vis[100005];

// Đồ thị vô hướng
// bool dfs(ll u, ll par) {
//     vis[u] = true;

//     for (auto &v : adj[u]) {
//         if (!vis[v]) {
//             if (dfs(v, u)) return true;
//         }
//         else if (v != par) return true;
//     }
        
//     return false;
// }

// Đồ thị có hướng
bool dfs(ll u) {
    color[u] = 1;
    for (auto &v : adj[u]) {
        if (color[v] == 0) {
            par[v] = u;
            if (dfs(v)) return true;
        }
        else if (color[v] == 1) return true;
    }
    color[u] = 2;
    return false;
}

void solve() {
    // n đỉnh, m cạnh
    cin >> n >> m;

    adj.resize(n+1);
    par.resize(n+1, 0);
    color.resize(n+1, 0);
    // fill(vis, vis + 100005, false);

    for (ll i = 1; i <= m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    // Nếu có nhiều thành phần liên thông
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (dfs(i)) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
