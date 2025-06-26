#include <bits/stdc++.h>
using namespace std;
#define ll long long

void countDivisor(ll n) {
    ll cnt = 0;
    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            if (i != n / i) cnt += 2;
            else ++cnt;
        }
    }

    cout << cnt << endl;
}

void countDivisor2(ll n) {
    ll res = 1;
    for (ll i = 2; i*i <= n; i++) {
        ll cnt = 0;
        while (n % i == 0) {
            ++cnt;
            n /= i;
        }

        res *= (cnt + 1);
    }

    if (n != 1) res *= 2;

    cout << res << endl;
}

void sumDivisor(ll n) {
    ll sum = 0;
    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            if (i != n / i) sum += i + n / i;
            else sum += i;
        }
    }

    cout << sum << endl;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    ll n; cin >> n;
    // Dem uoc so toi uu;
    countDivisor(n);
    // Dem uoc so theo so mu khi phan tich thua so nguyen to;
    countDivisor2(n);
    // Tinh tong uoc so toi uu;
    sumDivisor(n);
}
