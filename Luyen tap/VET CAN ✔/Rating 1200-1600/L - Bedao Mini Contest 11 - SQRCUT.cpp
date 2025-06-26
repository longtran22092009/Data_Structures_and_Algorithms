#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int a, b; cin >> a >> b;
    if (b > a) swap(a, b);

    int ans = 0;
    while (b != 0) {
        int turn = a / b, remain = a % b;
        a = b;
        b = remain;
        ans += turn;
    }

    cout << ans-1 << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll t; cin >> t;
    while (t--)
        solve();
}
