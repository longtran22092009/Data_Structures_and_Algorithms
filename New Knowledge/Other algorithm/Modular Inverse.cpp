#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

/*
    ## Nghịch đảo modulo ##

    x: a^-1
    =>  a * x đồng dư với m hay a * x % m = 1

    Điều kiện tồn tại nghịch đỏ modulo: gcd(a, m) = 1
    =>  a*x + m*y = 1 (Extended Euclidean Algorithm)

    Nếu m là số nguyên tố thì có thể tìm nghịch đảo modulo bằng định lí Euler
    =>  a^-1 = a^m-2
*/

ll x, y, g;

void extendedEuclidean(ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
        g = a; // GCD 
    }
    else {
        extendedEuclidean(b, a % b);

        ll tmp = x;
        x = y;
        y = tmp - a/b * y;
    }
}

// Sử dụng giải thuật Euclide mở rộng
void inverseModulo(ll a, ll m) {
    extendedEuclidean(a, m);

    if (g != 1) cout << "Không tồn tại nghịch đảo modulo!" << endl;
    else {
        // x có thể âm nên lấy giá trị dương 
        // => abs(x) % m = (x % m + m) % m 
        cout << (x % m + m) % m  << endl;
    }

}

// Sử dụng đinh lí Euler
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

void inverse(ll a, ll m) {
    cout << powMod(a, m-2, m) << endl;
}

void solve() {
    ll a, b; cin >> a >> b;
    inverseModulo(a, b);
    inverse(a, b);
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
