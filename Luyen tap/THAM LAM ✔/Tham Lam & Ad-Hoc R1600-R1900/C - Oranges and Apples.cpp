#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


struct Item {
    ll x, y, id;
};

const int mxN = 100005, INF = (int) 1e9+5;
ll apple = 0, orange = 0;

bool comp(Item &a, Item &b) {
    return a.x > b.x;
}

void solve() {
    int n; cin >> n;

    vector <Item> a(2*n);

    for (int i = 1; i <= 2*n-1; i++) {
        ll x, y; cin >> x >> y;
        a[i] = {x, y, i};
        apple += x;
        orange += y;
    }
    sort(a.begin()+1, a.end(), [&](Item &a, Item &b) { return a.x > b.x; });

    cout << "YES\n" << a[1].id << " "; // The largest amount apple always larger than half of it
    for (int i = 2; i <= 2*n-1; i += 2) { // Get half of all boxes
        // Between 2 any box, get the larger => Always correct
        if (a[i].y > a[i+1].y) cout << a[i].id << " ";
        else cout << a[i+1].id << " ";
    }
    cout << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll t; cin >> t;
    while (t--)
        solve();
}
