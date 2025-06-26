#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, Q; cin >> n >> Q;

    vector <int> ans(n+1), order(Q+1);

    for (int i = 1; i <= n; i++) ans[i] = i;
    for (int i = 1; i <= Q; i++) cin >> order[i];
    // As last as top
    for (int i = Q; i >= 1; i--) {
        if (ans[order[i]] != -1) {
            cout << order[i] << endl;
            ans[order[i]] = -1; // already in the answer
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] != -1) cout << ans[i] << endl;
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
