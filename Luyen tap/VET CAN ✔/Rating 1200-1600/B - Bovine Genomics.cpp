#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "cownomics.in"
#define OUT "cownomics.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, m; cin >> n >> m;
    vector <string> a(n), b(n);
    // Spotty cows
    for (int i = 0; i < n; i++) cin >> a[i];
    // Plain cows
    for (int i = 0; i < n; i++) cin >> b[i];

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            for (int k = j+1; k < m; k++) {
                set <string> spotty;
                for (int x = 0; x < n; x++) {
                    spotty.insert(a[x].substr(i, 1)+a[x].substr(j, 1)+a[x].substr(k, 1));
                }

                bool ok = true;
                for (int x = 0; x < n; x++) {
                    if (spotty.count(b[x].substr(i, 1)+b[x].substr(j, 1)+b[x].substr(k, 1))) {
                        ok = false;
                        break;
                    }
                }
                cnt += ok;
            }
        }
    }

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
