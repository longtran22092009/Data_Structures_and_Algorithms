#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    Cho đồ thị vô hướng biểu diễn dưới dạng ma trận kề.
    Hãy chuyển đổi sang danh sách kề

    INPUT:
        Dòng đầu chứa 1 số n (1 <= n <= 1000)
        n dòng tiếp theo, mỗi dòng có n số biểu diễn ma trận kề
    OUTPUT:
        In ra danh sách kề tương ứng của đồ thị theo thứ tự tăng dần của đỉnh đầu

    VD: 5
        0 1 1 1 0 
        1 0 1 1 1 
        1 1 0 1 1 
        1 1 1 0 1 
        0 1 1 1 0 

    =>  1: 2 3 4 
        2: 1 3 4 5 
        3: 1 2 4 5 
        4: 1 2 3 5 
        5: 2 3 4 
*/


void solve() {
    ll n; cin >> n;
    
    vector <vector <ll>> adj(n+1);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll val; cin >> val;

            if (val == 1) {
                adj[i+1].push_back(j+1);
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto &x : adj[i]) {
            cout << x << " ";
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
