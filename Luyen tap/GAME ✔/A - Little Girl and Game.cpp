#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    string s; cin >> s;
    ll n = (ll) s.size();

    map <char, ll> freq;
    for (auto &ch : s) freq[ch]++;

    ll odd = 0;
    for (auto &x : freq) {
        if (x.second % 2 != 0) ++odd;
    }

    if (odd <= 1 || n % 2 != 0) cout << "First\n";
    else cout << "Second\n";
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
