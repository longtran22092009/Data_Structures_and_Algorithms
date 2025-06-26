#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

/*
    ## Giải thuật Euclide mở rộng ##

    a*x + b*y = gcd(a, b)

    VD: gcd(55, 80) = 5
    => 55*3 + 80*(-2) = 5

    # Công thức tổng quát:
    (x, y) = (1, 0) - kết thúc thuật tìm ước chung lớn nhất

    =>  { x = y1
        { y = (x1 - y1) * (a/b - làm tròn xuống)
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

void solve() {
    ll a, b; cin >> a >> b;
    extendedEuclidean(55, 80);

    cout << "GCD = " << g << endl << "=> ";
    cout << a << " * " << x << " + " << b << " * " << y << " = " << g << endl; 
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
