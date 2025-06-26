#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    Cho đồ thị vô hướng biểu diễn dưới dạng danh sách kề.
    Hãy chuyển đổi sang ma trận kề

    INPUT:
        Dòng đầu chứa 1 số n (1 <= n <= 1000)
        n dòng tiếp theo, mỗi dòng biểu diễn danh sách kề của 1 đỉnh
    OUTPUT:
        In ra ma trận kề tương ứng của đồ thị

    VD: 5
        2 3 4 
        1 3 4 5 
        1 2 4 5 
        1 2 3 5 
        2 3 4 

    =>  0 1 1 1 0 
        1 0 1 1 1 
        1 1 0 1 1 
        1 1 1 0 1 
        0 1 1 1 0
*/


void solve() {
    ll n; cin >> n;
    // cin.ignore(count, delimiter)
    // count: số kí tự bỏ qua (mặc định là 1)
    // delimiter: kí tự sẽ bỏ qua (mặc định là "\n")
    cin.ignore();
    
    vector <vector <ll>> adj_matrix(n+1, vector <ll> (n+1, 0));

    for (ll i = 1; i <= n; i++) {
        string s, j; 
        // Cin cả dòng theo cin.ignore()
        getline(cin, s);

        // Tách từng kí tự trong chuỗi ra
        stringstream ss(s);
        while (ss >> j) {
            // Ép kiểu string thành long long
            adj_matrix[i][stoll(j)] = adj_matrix[stoll(j)][i] = 1;
        }
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
