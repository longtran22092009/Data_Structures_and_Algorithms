#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

/*
  -- Danh sách cạnh --

  * Thường dùng làm input của các bài toán đồ thị *
  * Dùng khi số cạnh thưa: Số cạnh <= 6 lần số đỉnh *

  * Ưu điểm:
    Tiết kiệm bộ nhớ nếu đồ thị thưa, thuận lợi cho các bài toán chỉ liên quan đến cạnh của bài toán

  * Nhược điểm:
    Khi cần duyệt các đỉnh kề với một đỉnh bất kì thì phải duyệt cả danh sách cạnh

  VD:
    1-3-5
    |\|\|
    2-4-6

=> đầu cuối
    1   2
    1   3
    1   4
    2   4
    3   4
    3   5
    3   6
    4   6
    5   6
*/

/*
  n là số đỉnh, m là số cạnh

  # Đồ thị vô hướng:
    Chỉ cần biểu diễn cạnh (u, v), không cần (v, u)
  
  # Đồ thị có hướng:
    Xét thứ tự đỉnh đầu cuối tướng ứng hướng của cạnh đó
    (u, v) != (v, u)

  ## Không có trọng số:
    Lưu bằng:
      pair <int, int> edge = {u, v}

  ## Có trọng số:
    Lưu bằng:
      tuple <int, int, int> edge = {u, v, w}
    hay
      struct {
          int u, v, w;
      }

      w là trọng số
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
