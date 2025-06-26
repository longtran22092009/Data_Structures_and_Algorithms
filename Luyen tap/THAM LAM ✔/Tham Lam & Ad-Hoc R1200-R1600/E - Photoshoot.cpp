#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0, type = -1;
    for (int i = 0; i < n; i += 2) {
        string sub = s.substr(i, 2);
        // 0: GH, 1: HG
        if (sub == "GG" || sub == "HH") continue;
        if (sub == "GH") {
            if (type == 1) ++cnt;
            type = 0;
        }
        else if (sub == "HG") {
            if (type == 0) ++cnt;
            type = 1;
        }
    }

    if (type == 0) ++cnt;
    cout << cnt << endl;
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
