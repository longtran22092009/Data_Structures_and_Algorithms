#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    Cho đồ thị vô hướng biểu diễn dưới dạng ma trận kề.
    Hãy chuyển đổi sang danh sách cạnh

    INPUT:
        Dòng đầu chứa 1 số n (1 <= n <= 1000)
        n dòng tiếp theo, mỗi dòng có n số biểu diễn ma trận kề
    OUTPUT:
        In ra danh sách cạnh tương ứng của đồ thị theo thứ tự tăng dần của đỉnh đầu

    VD: 5
        0 1 1 1 0 
        1 0 1 1 1 
        1 1 0 1 1 
        1 1 1 0 1 
        0 1 1 1 0 

    =>  1 2
        1 3
        1 4
        2 3
        2 4
        2 5
        3 4
        3 5
        4 5
*/


void solve() {
    ll n; cin >> n;
    
    vector <pair <ll, ll>> edge_lst;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll val; cin >> val;

            if (j > i && val == 1) {
                edge_lst.push_back({i+1, j+1});
            }
        }
    }

    for (auto &x : edge_lst) cout << x.first << " " << x.second << endl;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    solve();
}
