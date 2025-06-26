#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    ll n, x; cin >> n >> x;

    vector <pair <ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n-2; i++) {
        int l = i+1, r = n-1;
        while (l < r) {
            ll sum = a[i].first + a[l].first + a[r].first;
            if (sum == x) {
                cout << a[l].second << " " << a[r].second << " " << a[i].second << endl;
                return;
            }
            else if (sum > x) --r;
            else ++l;
        }
    }

    cout << "IMPOSSIBLE\n";
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}
