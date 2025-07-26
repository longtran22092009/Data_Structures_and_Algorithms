#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 1000005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18, MOD = (ll) 1e9+7;

struct Fenwick {
    int N;
    vector<ll> bit;

    Fenwick(int n) { // 0-based
        N = n;
        bit.assign(N + 1, 0);
    }

    // Cộng thêm val vào vị trí idx
    void update(int idx, ll val) {
        for (++idx; idx <= N; idx += idx & -idx)
            bit[idx] += val;
    }

    // Tính tổng từ 1 đến idx
    ll query(int idx) {
        ll res = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    // Tổng từ l đến r
    ll range_query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(max(0, l - 1));
    }
};

void solve() {
    int n; cin >> n;

    vector <tuple <int, int, int, int>> events; // {pos, type, top, bottom}
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        // 1: start, 2: vertical, 3: end
        // Should check for intersection before end of segment

        if (x1 == x2) events.push_back({x1, 2, y1, y2});
        else {
            events.push_back({x1, 1, y1, y1});
            events.push_back({x2, 3, y1, y1});
        }
    }
    sort(events.begin(), events.end());

    ll ans = 0;
    Fenwick BIT(2 * mxN);

    for (auto &e : events) {
        int pos, type, bottom, top;
        tie(pos, type, bottom, top) = e;
        top += 1e6;
        bottom += 1e6;

        if (type == 1) BIT.update(top, 1);
        else if (type == 3) BIT.update(top, -1);
        else ans += BIT.range_query(bottom, top);
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}


// Segment Tree range sum
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"
 
 
const int mxN = 1000005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18, MOD = (ll) 1e9+7;
 
// Tree node v represents [l, r)
struct segtree {
    int N;
    vector <ll> tree;
 
    void init(int n) {
        N = n;
        tree.assign(4 * N, 0ll);
    }
 
    void update(int pos, int val) {
        auto self = [&](auto&& self, int pos, int val, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] += val;
                return;
            }
 
            int mid = (l + r) / 2;
            if (pos < mid) self(self, pos, val, 2 * v + 1, l, mid);
            else self(self, pos, val, 2 * v + 2, mid, r);
 
            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        };
        self(self, pos, val, 0, 0, N);
    }
 
    ll query(int ql, int qr) {
        auto self = [&](auto&& self, int ql, int qr, int v, int l, int r) -> ll {
            if (qr <= l || ql >= r) return 0;
            if (ql <= l && r <= qr) return tree[v];
 
            int mid = (l + r) / 2;
            ll s1 =  self(self, ql, qr, 2 * v + 1, l, mid);
            ll s2 =  self(self, ql, qr, 2 * v + 2, mid, r);
            return s1 + s2;
        };
        return self(self, ql, qr, 0, 0, N);
    }
};
 
void solve() {
    int n; cin >> n;
 
    vector <tuple <int, int, int, int>> events; // {pos, type, top, bottom}
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        // 1: start, 2: vertical, 3: end
        // Should check for intersection before end of segment
 
        if (x1 == x2) events.push_back({x1, 2, y1, y2});
        else {
            events.push_back({x1, 1, y1, y1});
            events.push_back({x2, 3, y1, y1});
        }
    }
    sort(events.begin(), events.end());
 
    ll ans = 0;
    segtree st;
    st.init(2 * mxN);
 
    for (auto &e : events) {
        int pos, type, bottom, top;
        tie(pos, type, bottom, top) = e;
        top += 1e6;
        bottom += 1e6;
 
        if (type == 1) st.update(top, 1);
        else if (type == 3) st.update(top, -1);
        else ans += st.query(bottom, top + 1);
    }
 
    cout << ans << endl;
}
 
signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }
 
    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();
 
    // ll t; cin >> t;
    // while (t--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}
*/