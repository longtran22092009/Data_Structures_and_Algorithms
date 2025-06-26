#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;

    int more = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        x += more;
        int remain = ((n-i == 0)? x : x % (n-i));

        cout << remain << endl;
        more += ((n-i == 0)? 0 : x / (n-i));
    }
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
