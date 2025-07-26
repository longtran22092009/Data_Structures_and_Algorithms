#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9 + 5;
int n, k;
vector <pair <int, int>> a, ans;

void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        a.push_back({l, 0});
        a.push_back({r, 1});
    }
    sort(a.begin(), a.end());

    int cnt = 0, st = INF;
    for (int i = 0; i < n*2; i++) {
        if (a[i].second == 0) {
            ++cnt;
            if (cnt >= k && st == INF) {
                st = a[i].first;
            }
        }
        else {
            --cnt;
            if (cnt < k && st != INF) {
                ans.push_back({st, a[i].first});
                st = INF;
            }
        }
    }

    // for (auto &x : a) cout << x.first << ": " << x.second << endl;
    // cout << endl;
    cout << ans.size() << endl;
    for (auto &x : ans) cout << x.first << " " << x.second << endl;
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
