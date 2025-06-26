#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int Q; cin >> Q;

    while (Q--) {
        int limit; cin >> limit;
        char favor; cin >> favor;

        vector <int> val, dis;
        int lastId = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != favor) continue;
            int j = i;
            while (j+1 < n && s[j+1] == s[i]) ++j;
            // cerr << i << " " << j << endl;
            val.push_back(j-i+1);
            if (lastId != -1) dis.push_back(i-lastId-1);

            lastId = j;
            i = j;
        }

        int m = val.size(), l = 0;
        int curr_len = 0, curr_dis = 0, ans = 0;
        for (int r = 0; r < m; r++) {
            curr_len += val[r];
            // cerr << "Current length: " << curr_len << endl;
            if (r > 0) curr_dis += dis[r-1];
            // cerr << "Current distance: " << curr_dis << endl;
            
            while (l <= r && curr_dis > limit) {
                curr_len -= val[l];
                curr_dis -= dis[l];
                ++l;
            }

            ans = max(ans, curr_len);
            // cerr << "Answer: " << ans << endl;
        }

        cout << ans + min(limit, n-ans) << endl;
    }
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    // ll t; cin >> t;
    // while (t--)
    solve();
}