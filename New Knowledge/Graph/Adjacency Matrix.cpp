#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

 

/*
  -- Ma trận kề --
  * Ưu điểm:
    Đơn giản, dễ cài đặt (mảng 2 chiều)
    Dễ kiểm tra xem 2 đỉnh có kề nhau không trong O(1) bằng giá trị a[i][j]

  * Nhược điểm:
    Kiểm tra xem một đỉnh có bao nhiêu đỉnh kề tốn O(n) - xét một hàng / cột

    Tốn bộ nhớ nên không thể biểu diễn đồ thị với số đỉnh lớn
    Space complexity :O(n^2)

  VD:
    1-3-5
    |\|\|
    2-4-6

=>    1 2 3 4 5 6

  1  |0|1|1|1|0|0|
  2  |1|0|0|1|0|0|
  3  |1|0|0|1|1|1|
  4  |1|1|1|0|0|1|
  5  |0|0|1|0|0|1|
  6  |0|0|1|1|1|0|
*/

/*
  n là số đỉnh, m là số cạnh

  ## Không có trọng số ##
  a(i, j) = 1 nếu (i, j) là một cạnh của đồ thị 
  a(i, j) = 0 nếu (i, j) không là một cạnh của đồ thị

  # Đồ thị vô hướng (Đối xứng):
  Số bậc bằng tổng phần tử trên một hàng / cột

  # Đồ thị có hướng (Có thể không đối xứng):
  Số bán bậc ra là tổng phần tử trên một hàng
  Số bán bặc vào là tổng phần tử trên một cột

  ## Có trọng số ##
  a(i, j) = trọng số nếu (i, j) là một cạnh của đồ thị 
  a(i, j) = 0 (hoặc vô cùng, âm vô cùng,... tùy theo bài toán) nếu (i, j) không là một cạnh của đồ thị
  
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
