#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    ## Hoán vị lạc chỗ ##
    Đếm số hoán vị không có phần tử nào nằm đúng vị trí ban đầu, kí hiệu là D(n)
    VD: 1234 có các hoán vị phải thỏa a[i] != i

    Công thức:
        (1) D(n) = n! * sum((-1)^k / k!) với k chạy từ 0 tới n
        (2) D(n) = n!/e + 1/2 (làm tròn xuống) với e khoảng 2.71828
        (3) D(n) = (n-1)*(Dn-1 + Dn-2) -hay dùng--
*/


const double e = M_E;

void solve() {
    ll ans = (120/e) + 1/2; // 5! = 120
    cout << ans;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}
