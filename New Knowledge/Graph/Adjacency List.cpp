#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

/*
  -- Danh sách cạnh --

  * Thường dùng làm input của các thuật toán*

  * Ưu điểm:
    Dễ dàng duyệt các đỉnh kề của một đỉnh
    Đễ dàng duyệt các cạnh của đồ thị trong mỗi danh sách kề
    Tối ưu về phương pháp biểu diễn

  * Nhược điểm:
    (Khó với người lập trình yếu)

  VD:
    1-3-5
    |\|\|
    2-4-6

=>  1: {2, 3, 4}
    2: {1, 4}
    3: {1, 4, 5, 6}
    4: {1, 2, 3, 6}
    5: {3, 6}
    6: {3, 4, 5}
*/

/*
  n là số đỉnh, m là số cạnh

  Lưu bằng:
    vector <vector <int>> adj = {a, b, c, ...}
*/

void solve() {
    cout << __cplusplus;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    solve();
}
