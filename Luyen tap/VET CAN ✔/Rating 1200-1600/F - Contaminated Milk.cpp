#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "badmilk.in"
#define OUT "badmilk.out"

struct Event {
    int who, type, time;
};

const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, m, d, s;
    cin >> n >> m >> d >> s;

    vector <Event> events(d+1);
    vector <int> sick(n+1, -1);

    // Parse the input
    for (int i = 1; i <= d; i++) {
        int p, m, t; cin >> p >> m >> t;
        events[i] = {p, m, t};
    }
    for (int i = 1; i <= s; i++) {
        int p, t; cin >> p >> t;
        sick[p] = t;
    }
    
    // Milk i is bad
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        set <int> drunk;
        for (auto &ev : events) {
            if (ev.type == i) {
                if (ev.time < sick[ev.who]) {
                    drunk.insert(ev.who);
                }
            }
        }
        
        if (drunk.size() == s) {
            for (auto &ev : events) {
                if (ev.type == i) {
                    if (sick[ev.who] == -1) {
                        drunk.insert(ev.who);
                    }
                }
            }
            ans = max(ans, (int) drunk.size());
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
