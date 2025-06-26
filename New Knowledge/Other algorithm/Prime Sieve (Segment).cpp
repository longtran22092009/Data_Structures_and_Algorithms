#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sieve(ll n) {
    vector <bool> prime(n+1, 1);

    for (ll i = 2; i*i <= n; i++) {
        for (ll j = i*i; j <= n; j += i) {
            prime[j] = 0;
        }
    }

    for (ll i = 1; i <= n; i++) {
        if (prime[i]) cout << i << " ";
    }
}

void segment_sieve(ll l, ll r) {
    vector <bool> prime(r-l+1, 1);

    for (ll i = 2; i*i <= r; i++) {
        for (ll j = max(i*i, (l+i-1)/i*i); j <= r; j += i) {
            prime[j-l] = 0;
        }
    }

    for (ll i = max(l, 2ll); i <= r; i++) {
        if (prime[i-l]) cout << i << " ";
    }
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    ll n, l, r; cin >> n >> l >> r;
    // Sieve from 1 to n;
    sieve(n);
    cout << endl;
    
    // Sieve in [l, r] segment;
    segment_sieve(l, r);
}
