#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

// 1 2 2 2 1 1 1 2 1
void solve() {
    ll n, k; cin >> n >> k;

    vector <ll> a(n);
    map <ll, ll> freq;

    for (auto &x : a) {
        cin >> x;
        freq[x]++;
    }
    // 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4 1

    if (freq.size() > k) {
        cout << "-1\n";
        return;
    }

    // 2 3 4 2 3 4
    else {
        cout << n*k << endl;
        for (ll i = 0; i < n; i++) {
            for (auto &x : freq) cout << x.first << " ";

            for (ll i = 0; i < k-freq.size(); i++) cout << "1 ";
        }
    }
  
    cout << endl;
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll t; cin >> t;
    while (t--)
        solve();
}
