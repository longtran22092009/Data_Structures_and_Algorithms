#include <bits/stdc++.h>
using namespace std;
#define ll long long

void pt(ll n) {
    for (ll i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    if (n != 1) cout << n;
    cout << endl;
}

void pt2(ll n) {
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            ll cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }

            printf("%d(%d) ", i, cnt);
        }
    }

    cout << endl;
}

void pt3(ll n) {
    for (ll i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            cout << i;
            n /= i;

            if (n != 1) cout << "x";
        }
    }

    if (n != 1) cout << n;
    cout << endl;
}

void pt4(ll n) {
    cout << n << " = ";
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            ll cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }

            printf("%d^%d", i, cnt);
            if (n != 1) cout << " * ";
        }
    }

    cout << endl;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    ll n; cin >> n;
    cout << "In ra cac thua so nguyen to: " << endl;
    pt(n);
    cout << "In ra cac thua so nguyen to kem so mu: " << endl;
    pt2(n);
    cout << "In ra cac thua so nguyen to co dau x: " << endl;
    pt3(n);
    cout << "In ra cac thua so nguyen to viet co mu: " << endl;
    pt4(n);
}
