#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;
    int numOdd = 0, numEven = 0;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x % 2 == 0) ++numEven;
        else ++numOdd;
    }
    // Odd + odd = Even + even = even
    // Odd + even = odd
    if (numEven >= numOdd) {
        int ans = 2 * numOdd;
        if (numEven - numOdd > 0) ++ans;
        cout << ans << endl;
    }
    else {
        int ans = 2*numEven;
        numOdd -= numEven;
        // Two odd in a group to be even, and one in another group
        ans += 2 * (numOdd / 3); 
        numOdd %= 3;
        // Num of remain odd if equap to 1 
        // we could put it with the last odd group
        // to an odd group before and it sum still odd
        if (ans > 0 && numOdd == 1) --ans;
        else if (numOdd == 2) ++ans; // Two odd in a group

        cout << ans << endl;
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
