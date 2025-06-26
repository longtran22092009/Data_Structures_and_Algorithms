#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    Cho đồ thị vô hướng biểu diễn dưới dạng danh sách cạnh.
    Hãy chuyển đổi sang ma trận kề

    INPUT:
        Dòng đầu chứa 2 số n, m (1 <= n <= 1000, 1 <= m <= n*(n-1)/2)
        m dòng tiếp theo là 2 số u, v biểu diễn cạnh u, v của đồ thị (1 <= u, v <= n)
        Các cạnh được liệt kê theo thứ tự tăng dần của đỉnh đầu
    OUTPUT:
        In ra ma trận kề tương ứng của đồ thị

    VD: 5 9
        1 2
        1 3
        1 4
        2 3
        2 4
        2 5
        3 4
        3 5
        4 5

    =>  0 1 1 1 0 
        1 0 1 1 1 
        1 1 0 1 1 
        1 1 1 0 1 
        0 1 1 1 0 
*/


void solve() {
    ll n, m; cin >> n >> m;

    vector <vector <ll>> adj_matrix(n+1, vector <ll> (n+1, 0));

    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj_matrix[u][v] = adj_matrix[v][u] = 1;
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    solve();
}
