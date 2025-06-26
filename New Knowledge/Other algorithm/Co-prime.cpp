#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    ll a, b; cin >> a >> b;
    if (gcd(a, b) == 1) cout << "YES";
    else cout << "NO";
}
