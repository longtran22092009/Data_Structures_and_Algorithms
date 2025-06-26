#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

// Tree node v represents [l, r)
struct SegmentTree {
    int N;
    vector <ll> tree;

    void init(int n) {
        N = n;
        tree.assign(4 * N, 0ll);
    }

    void build(vector <ll> &a) {
        auto self = [&](auto&& self, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] = a[l];
                return;
            }

            int mid = (l + r) / 2;
            self(self, 2 * v + 1, l, mid);
            self(self, 2 * v + 2, mid, r);
            tree[v] = tree[2*v+1] + tree[2*v+2];
        };
        self(self, 0, 0, N);
    }

    void update(int pos, int val) {
        auto self = [&](auto&& self, int pos, int val, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] = val;
                return;
            }

            int mid = (l + r)/2;
            if (pos < mid)
                self(self, pos, val, 2 * v + 1, l, mid);
            else
                self(self, pos, val, 2 * v + 2, mid, r);

            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        };
        self(self, pos, val, 0, 0, N);
    }

    ll query(int ql, int qr) {
        auto self = [&](auto&& self, int ql, int qr, int v, int l, int r) -> ll {
            if (qr <= l || ql >= r) return 0;
            if (ql <= l && r <= qr) return tree[v];

            int mid = (l + r)/2;
            ll s1 =  self(self, ql, qr, 2 * v + 1, l, mid);
            ll s2 =  self(self, ql, qr, 2 * v + 2, mid, r);
            return s1 + s2;
        };
        return self(self, ql, qr, 0, 0, N);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vector <ll> a(n);
    for (auto &x : a) cin >> x;

    SegmentTree st;
    st.init(n);
    st.build(a);

    while (m--) {
        int op, i, v, l, r;
        cin >> op;

        if (op == 1) {
            cin >> i >> v;
            st.update(i, v);
        }
        else {
            cin >> l >> r;
            ll ans = st.query(l, r);
            cout << ans << endl;
        }
    }
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
