#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 200005, INF = (int) 1e9+5;
int n, k;
vector <int> a(mxN);
multiset <int> low, up;
// [low - med - up]

void adding(int val) {
    int curr_med = *low.rbegin();
    if (val > curr_med) {
        up.insert(val);
        if ((int) up.size() > k/2) {
            low.insert(*up.begin());
            up.erase(up.begin());
        }
    }
    else {
        low.insert(val);
        if ((int) low.size() > (k+1)/2) {
            up.insert(*low.rbegin());
            low.erase(--low.end());
        }
    }
}

void erasing(int val) {
    if (up.count(val)) up.erase(up.find(val));
    else low.erase(low.find(val));
    // Ensure low will have at least 1 element
    if (low.empty()) {
        low.insert(*up.begin());
        up.erase(up.begin());
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (k == 1) {
        for (int i = 0; i < n; i++) cout << "0 ";
        return;
    }

    int med = 0;
    ll sum = 0;
    // First sliding window
    low.insert(a[0]);
    for (int i = 1; i < k; i++) adding(a[i]);
    med = *low.rbegin();
    // Calculate the first window
    for (int i = 0; i < k; i++) sum += llabs(med - a[i]);
    cout << sum << " ";

    for (int i = k; i < n; i++) {
        int l = (int) low.size()-1, r = (int) up.size();
        // Update two sets
        erasing(a[i-k]);
        adding(a[i]);

        int new_med = *low.rbegin(), diff = new_med - med;
        // Adjust the sum
        sum += (l*diff - r*diff); 
        // Remove the element out of the window
        sum -= abs(a[i-k] - med);
        // Add the new element to the window
        sum += abs(a[i] - new_med); 
        // Update the median
        med = new_med;

        cout << sum << " ";
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