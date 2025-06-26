#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    # Tích 2 ma trận

    Điều kiện: số hàng ma trận a bằng số cột ma trận b
    a[x][y] và b[u][v] => y = u 

    Lấy các phần tử của hàng i nhân vói các phần tử ở cột j
    c[i][j] = sum (a[i][k] * b[k][j])
*/

const ll MOD = (ll) 1e9 + 7;

// Nhân hai ma trận a, b và lưu kết quả vào lại ma trận a
void matrixMultiply(vector <vector <ll>> &a, vector <vector <ll>> &b) {
    vector <vector <ll>> res(2, vector <ll>(2));

    for (ll i = 0; i < 2; i++) {
        for (ll j = 0; j < 2; j++) {
            res[i][j] = 0;
            
            for (ll k = 0; k < 2; k++) {
                res[i][j] += a[i][k] * b[k][j] % MOD;
            }
        }
    }

    for (ll i = 0; i < 2; i++) {
        for (ll j = 0; j < 2; j++) {
            a[i][j] = res[i][j];
        }
    }
}

void solve() {
    cout << __cplusplus;
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