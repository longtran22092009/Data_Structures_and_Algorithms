#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/* 
    # (Hai đỉnh của một cạnh khác nhau) - Hay dùng
      (Cạnh có hường gọi là cung. VD: cung AB - mũi tên từ A sang B)
      Đơn đồ thị vô hướng / có hướng
      Đa đồ thị vô hướng / có hướng

    # (Hai đỉnh của một cạnh không nhất thiết phải khác nhau) - Ít dùng
      Giả đồ thị vô hướng - cạnh bắt đầu và kết thúc cùng cạnh là cạnh khuyên

    # Đỉnh kề và cạnh liên thuộc:
      Hai đỉnh có đường nối từ đỉnh này sang đỉnh kia gọi là hai đỉnh kề nhau
      Còn cạnh nối hai đỉnh kề nhau là cạnh liên thuộc
      VD: A, B là hai đỉnh kề nhau nếu có cạnh AB
      và cạnh AB là cạnh liên thuộc

    # Bậc của đỉnh trên đồ thị vô hướng - kí hiệu là deg(u):
      Bậc là số cạnh liên thuộc của một đỉnh - số cạnh đi ra các đỉnh khác từ đỉnh đó
      Đỉnh có số bậc bằng 0 là đỉnh cô lập
      Đỉnh có số bậc bằng một là đỉnh treo
      (Đồ thị có m cạnh thì tổng số bậc là 2*m)

    # Bán bậc của đỉnh trên đồ thị có hướng - kí hiệu là (deg+(u), deg-(u)):
      Bán bậc ra: số cung đi ra từ đỉnh u - kí hiệu là deg+(u):
      Bán bậc vào: số cung đi vào đỉnh u - kí hiệu là deg-(u):
      (Đồ thị có m cạnh thì tổng số bán bậc ra = tổng số bán bậc vào = m)

    # Đường đi trên đồ thị:
      Là dãy các đỉnh (hoặc dãy các cạnh) trong đó hai đỉnh liên tiếp có cạnh nối
      Đường đi đơn - các đỉnh không trùng nhau
      Độ dài đường đi là số cạnh trên đường đi

    # Chu trình:
      Là đường đi gồm các cạnh phân biệt và có điểm đầu trùng với điểm cuối
      Chu trình đơn - các đỉnh không trùng nhau trừ điểm đầu và điểm cuối

    (Chỉ có trên đồ thị vô hướng):
    # Liên thông:
      Đồ thị vô hướng gọi là liên thông nếu luôn tìm được một đườnh đi giữa hai cạnh bất kì
    
    # Thành phần liên thông:
      Đồ thị không liên thông thì sẽ phân rã thành các thành phần liên thông (Component)
      => Nếu đồ thị chỉ có một thành phần liên thông thì là đồ thị liên thông

    (Chỉ có trên đồ thị có hướng):
    # Liên thông mạnh, yếu:
      Mạnh - luôn tồn tại đường đi giữa hai cạnh u, v bất kì
      Yếu - nếu đồ thị vô hướng tương ứng là đồ thị liên thông (không có đỉnh cô lập)

      (Đồ thị vô hướng tương ứng là đồ thị có hướng bỏ hướng đi)
      (Đồ thị có hướng liên thông mạnh thì đương nhiên là đồ thị có hướng liên thông yếu)
*/

void solve() {
    cout << "Introduce to Graph: " << endl;

}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    solve();
}
