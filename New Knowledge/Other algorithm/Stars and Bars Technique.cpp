#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    # Bài toán chia kẹo của Euluer
    (1) Muốn chia n cái kẹo cho k đứa trẻ, mỗi đứa trẻ có ít nhất 1 cái kẹo

    * Sử dụng Stars and Bars Technique *
    Có n-1 vị trí để đặt k-1 thanh vào giữa n cái kẹo để chia làm k phần
    VD: n = 5, k = 3
    => * * * * * : n cái kẹo
        | | | |  : n-1 vị trí

    ==> *|* *|* * : cần k-1 thanh để chia đc k phần
    
    Vậy công thức là (n-1)C(k-1)

    (2)  Đếm có bao nhiêu cách thêm n phần tử giống nhau vào k nhóm 

    * Sử dụng Stars and Bars Technique *
    Có n+k-1 vị trí để đặt k-1 thanh và n phần tử 

    Vậy công thức là (n+k-1)C(k-1)
*/


void solve() {
    
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