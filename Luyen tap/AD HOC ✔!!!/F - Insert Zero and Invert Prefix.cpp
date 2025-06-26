#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;

    vector <ll> target(n);
    for (auto &x : target) cin >> x;

    if (target[n-1] == 1) {
        cout << "NO\n";
        return;
    }
    reverse(target.begin(), target.end());
    target.push_back(-1);

    cout << "YES\n";

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (target[i] == 0) cout << "0 ";
        else if (target[i] == 1) {
            ++cnt;
            if (target[i+1] == target[i]) cout << "0 ";
            else {
                cout << cnt << " ";
                cnt = 0;
            }
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
