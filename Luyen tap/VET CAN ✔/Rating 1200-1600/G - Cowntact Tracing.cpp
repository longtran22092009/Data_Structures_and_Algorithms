#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


struct Event {
    int time, x, y;
};

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, t; cin >> n >> t;
    string s; cin >> s;

    vector <int> final(n+1);
    for (int i = 0; i < n; i++) final[i+1] = s[i] - '0';

    vector <Event> events(t+1);
    for (int i = 1; i <= t; i++) {
        int time, x, y; cin >> time >> x >> y;
        events[i] = {time, x, y};
    }
    sort(events.begin(), events.end(), [](Event &a, Event &b) { return a.time < b.time; });
    // for (int i = 1; i <= t; i++) cout << events[i].time << " " << events[i].x << " " << events[i].y << endl;

    // Cow i is patient zero
    int possible = 0, minK = t, maxK = -1;
    for (int i = 1; i <= n; i++) {
        if (!final[i]) continue;

        bool ok = false;
        for (int k = 0; k <= t; k++) {
            vector <int> remainK(n+1, k);
            vector <int> res(n+1, 0);
            res[i] = 1;
            
            for (int j = 1; j <= t; j++) {
                int a = events[j].x, b = events[j].y;
                
                if (res[a] && remainK[a] && res[b] && remainK[b]) {
                    --remainK[a];
                    --remainK[b];
                }
                else if (res[a] && remainK[a]) {
                    --remainK[a];
                    res[b] = 1;
                }
                else if (res[b] && remainK[b]) {
                    --remainK[b];
                    res[a] = 1;
                }
            }
            
            bool valid = true;
            for (int i = 1; i <= n; i++) {
                if (final[i] != res[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ok = true;
                minK = min(minK, k);
                maxK = max(maxK, k);
            }
        }

        if (ok) ++possible;
    }

    cout << possible << " " << minK << " ";
    if (maxK == t) cout << "Infinity\n";
    else cout << maxK << endl;
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
