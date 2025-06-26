#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "balancing.in"
#define OUT "balancing.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, limit; cin >> n >> limit;

    vector <pair <int, int>> cows(n);
    set <int> dx, dy;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cows[i] = {x, y};
        dx.insert(x+1);
        dy.insert(y+1);
    }

    int ans = INF;
    for (auto &x : dx) {
        for (auto &y : dy) {
            vector <int> a(4);
            for (auto &c : cows) {
                if (c.first < x && c.second < y) a[0]++;
                else if (c.first < x && c.second > y) a[1]++;
                else if (c.first > x && c.second > y) a[2]++;
                else if (c.first > x && c.second < y) a[3]++;
            }
            ans = min(ans, *max_element(a.begin(), a.end()));
        }
    }

    cout << ans << endl;
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
