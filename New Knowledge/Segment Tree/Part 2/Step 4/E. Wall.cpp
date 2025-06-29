#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 2000005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

struct segtree {
    int N;
    vector <int> mn, mx, res;
    vector <pair <int, int>> lazy; // {low, high}

    segtree(int n) {
        N = n;
        mn.assign(4*N, 0);
        mx.assign(4*N, 0);
        lazy.assign(4*N, {-1, -1});
        res.assign(N, 0);
    }

    void push(int v, int l, int r) {
        if (lazy[v].first == -1) return;
        int low = lazy[v].first, high = lazy[v].second;

        if (r - l > 1) {
            // Left node
            if (lazy[2 * v + 1].first == -1) lazy[2 * v + 1] = lazy[v];
            else if (lazy[2 * v + 1].second <= lazy[v].first) lazy[2 * v + 1] = {low, low};
            else if (lazy[2 * v + 1].first >= lazy[v].second) lazy[2 * v + 1] = {high, high};
            else {
                lazy[2 * v + 1].first = max(lazy[2 * v + 1].first, lazy[v].first);
                lazy[2 * v + 1].second = min(lazy[2 * v + 1].second, lazy[v].second);
            }
            // Right node
            if (lazy[2 * v + 2].first == -1) lazy[2 * v + 2] = lazy[v];
            else if (lazy[2 * v + 2].second <= lazy[v].first) lazy[2 * v + 2] = {low, low};
            else if (lazy[2 * v + 2].first >= lazy[v].second) lazy[2 * v + 2] = {high, high};
            else {
                lazy[2 * v + 2].first = max(lazy[2 * v + 2].first, lazy[v].first);
                lazy[2 * v + 2].second = min(lazy[2 * v + 2].second, lazy[v].second);
            }
        }

        if (mx[v] <= lazy[v].first) mn[v] = mx[v] = lazy[v].first;
        else if (mn[v] >= lazy[v].second) mn[v] = mx[v] = lazy[v].second;
        else if (r - l > 1) {
            mn[v] = max(mn[v], low);
            mx[v] = min(mx[v], high);
        }

        lazy[v] = {-1, -1};
    }
    
    void update(int ul, int ur, int val, int op) {
        auto self = [&](auto&& self, int ul, int ur, int val, int v, int l, int r) -> void {
            push(v, l, r);
            if (r <= ul || l >= ur) return;
            if (ul <= l && r <= ur) {
                if (op == 1) lazy[v] = {val, INF};
                else lazy[v] = {0, val};
                push(v, l, r);
                return;
            }                     
            
            int mid = (l + r) / 2;
            self(self, ul, ur, val, 2 * v + 1, l, mid);
            self(self, ul, ur, val, 2 * v + 2, mid, r);
            
            mn[v] = min(mn[2 * v + 1], mn[2 * v + 2]);
            mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
        };
        self(self, ul, ur, val, 0, 0, N);
    }

    void query() {
        auto self = [&](auto&& self, int v, int l, int r) -> void {
            push(v, l, r);
            if (r - l == 1) {
                res[l] = mn[v];
                return;
            }
            
            int mid = (l + r) / 2;
            self(self, 2 * v + 1, l, mid);
            self(self, 2 * v + 2, mid, r);
        };
        self(self, 0, 0, N);
    }
};

void solve() {
    int n, k; cin >> n >> k;

    segtree st(n);
    while (k--) {
        int op, l, r, h;
        cin >> op >> l >> r >> h;
        st.update(l, r+1, h, op);
    }

    st.query();
    for (auto &x : st.res) cout << x << '\n';
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
