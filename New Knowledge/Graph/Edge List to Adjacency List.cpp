#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    Cho đồ thị vô hướng biểu diễn dưới dạng danh sách cạnh.
    Hãy chuyển đổi sang danh sách kề

    INPUT:
        Dòng đầu chứa 2 số n, m (1 <= n <= 1000, 1 <= m <= n*(n-1)/2)
        m dòng tiếp theo là 2 số u, v biểu diễn cạnh u, v của đồ thị (1 <= u, v <= n)
        Các cạnh được liệt kê theo thứ tự tăng dần của đỉnh đầu
    OUTPUT:
        In ra danh sách kề tương ứng của đồ thị, liệt kê theo thứ tự tăng dần của các đỉnh

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

    =>  1: 2 3 4 
        2: 1 3 4 5 
        3: 1 2 4 5 
        4: 1 2 3 5 
        5: 2 3 4 
*/


void solve() {
    ll n, m; cin >> n >> m;

    vector <vector <ll>> adj(n+1);

    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto &x : adj[i]) cout << x << " ";
        cout << "" << endl;
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
