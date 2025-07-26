#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 200005, INF = (int) 1e9+5;

void solve() {
    int n, k; cin >> n >> k;

    vector <int> a(n);
    for (auto &x : a) cin >> x;
    
    map <int, set <int>> mode;
    unordered_map <int, int> freq;
    for (int i = 0; i < k; i++) ++freq[a[i]];
    for (auto &x : freq) mode[x.second].insert(x.first);
    cout << *(mode.rbegin()->second).begin() << " ";

    for (int i = k; i < n; i++) {
        // Add new element
        if (mode[freq[a[i]]].count(a[i])) mode[freq[a[i]]].erase(a[i]);
        if ((int) mode[freq[a[i]]].size() == 0) mode.erase(freq[a[i]]);
        ++freq[a[i]];
        mode[freq[a[i]]].insert(a[i]);
        // Remove old lement
        if (mode[freq[a[i-k]]].count(a[i-k])) mode[freq[a[i-k]]].erase(a[i-k]);
        if ((int) mode[freq[a[i-k]]].size() == 0) mode.erase(freq[a[i-k]]);
        --freq[a[i-k]];
        mode[freq[a[i-k]]].insert(a[i-k]);

        ll ans = *(mode.rbegin()->second).begin();
        cout << ans << " ";
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