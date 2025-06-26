#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "race.in"
#define OUT "race.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int k, n; cin >> k >> n;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;

        int sumUp = 0, sumDown = 0, time = 0;
        for (int curr = 1;; curr++) {
            sumUp += curr;
            ++time;

            if (sumUp + sumDown >= k) break;

            if (curr >= x) {
                sumDown += curr;
                ++time;

                if (sumUp + sumDown >= k) break;
            }
        }

        cout << time << endl;
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
