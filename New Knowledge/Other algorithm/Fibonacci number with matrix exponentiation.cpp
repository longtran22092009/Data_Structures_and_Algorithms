#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    # Tính số fibonacci bằng nhân ma trận - O(logN)
    1 <= n <= 10^18

           n 
    ([1 1])      =>  [F(n+1) F(n)]
    ([1 0])      =>  [F(n) F(n-1)]
*/

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
                res[i][j] %= MOD;
            }
        }
    }

    for (ll i = 0; i < 2; i++) {
        for (ll j = 0; j < 2; j++) {
            a[i][j] = res[i][j];
        }
    }
}

// Lũy thừa nhị phân - O(logN)
ll matrixBinpow(ll n) {
    // Mảng đơn vị - {{1, 0}, {0, 1}}
    vector <vector <ll>> res = {{1, 0}, {0, 1}};

    // Mảng khởi tạo trong công thức
    vector <vector <ll>> a = {{1, 1}, {1, 0}};

    while (n) {
        if (n % 2 == 1) {
            matrixMultiply(res, a);
        }

        matrixMultiply(a, a);
        n /= 2;
    }

    return res[0][1]; // res[1][0]
}

void solve() {
    ll n; cin >> n;

    cout << matrixBinpow(n) << endl;
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