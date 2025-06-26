#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    Cho đồ thị vô hướng biểu diễn dưới dạng danh sách kề.
    Hãy chuyển đổi sang danh sách cạnh

    INPUT:
        Dòng đầu chứa 1 số n (1 <= n <= 1000)
        n dòng tiếp theo, mỗi dòng biểu diễn danh sách kề của 1 đỉnh
    OUTPUT:
        In ra danh sách cạnh tương ứng của đồ thị

    VD: 5
        2 3 4 
        1 3 4 5 
        1 2 4 5 
        1 2 3 5 
        2 3 4 

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
    // cin.ignore(count, delimiter)
    // count: số kí tự bỏ qua (mặc định là 1)
    // delimiter: kí tự sẽ bỏ qua (mặc định là "\n")
    cin.ignore();
    
    vector <pair <ll, ll>> edge_lst;

    for (ll i = 1; i <= n; i++) {
        string s, j; 
        // Cin cả dòng theo cin.ignore()
        getline(cin, s);

        // Tách từng kí tự trong chuỗi ra
        stringstream ss(s);
        while (ss >> j) {
            // Ép kiểu string thành long long
            if (stoll(j) > i) edge_lst.push_back({i, stoll(j)});
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
