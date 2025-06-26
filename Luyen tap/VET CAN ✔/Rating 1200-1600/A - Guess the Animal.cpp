#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "guess.in"
#define OUT "guess.out"


const int mxN = 105, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;

    vector <vector <string>> a(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int diff; cin >> diff;
        for (int j = 0; j < diff; j++) {
            string t; cin >> t;
            a[i].push_back(t);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) { // Animal i is choosed
        for (int j = i+1; j < n; j++) {
            int cnt = 0;
            for (auto &x : a[i]) {
                for (auto &y : a[j]) {
                    if (x == y) ++cnt;
                }
            }
            
            ans = max(ans, cnt);
        }
    }

    // Number of most common characteristics + 1 final yes to guess which animal
    cout << ans+1 << endl;
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
