#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


ll MOD = (ll) 1e9 + 7;

// Tính tổ hợp chập k của n (0 <= k,n <= 1000)
// Kết quả chia dư 10^9 + 7

ll C[10000][10000];
// C[i][j]: tổ hợp chập j của i

void findAllCombination() {
    for (ll i = 0; i <= 1000; i++) {
        for (ll j = 0; j <= i; j++) {
            if (j == 0 || i == j) {
                C[i][j] = 1;
            }
            else {
                C[i][j] = C[i-1][j] + C[i-1][j-1];
                C[i][j] %= MOD;
            }
        }
    }
}

// Tính tổ hợp chập k của n (0 <= k,n <= 1000)
// Kết quả chia dư 10^9 + 7

ll powMod(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    
    while (b) {
        if (b % 2 == 1) {
            res *= a;
            res %= m;
        }

        a *= a;
        a %= m;
        b /= 2;
    }

    return res;
}

// Chỉ dùng khi m là số nguyên tố
ll inverse(ll a, ll m) {
    return powMod(a, m-2, m);
}

// Lưu các giá trị giai thừa
vector <ll> f(1000001);

void solve() {
    // findAllCombination();
    
    ll n, k; cin >> n >> k;
    
    f[0] = 1; // 0! = 1
    // Mảng tích
    for (ll i = 1; i <= n; i++) {
        f[i] = i * f[i-1];
        f[i] %= MOD;
    }

    cout << f[n] % MOD * inverse(f[k] * f[n-k] % MOD, MOD) % MOD;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    solve();
}
