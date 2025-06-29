#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

struct segtree {
    int N;
    vector <tuple <ll, ll, ll, ll>> tree;
    vector <ll> lazy;

    segtree(int n) {
        N = n;
        tree.assign(4*N, tuple<ll, ll, ll, ll>());
        lazy.assign(4*N, -LINF);
    }

    void push(int v, int l, int r) {
        if (lazy[v] != -LINF && r - l > 1) {
            int mid = (l + r) / 2;
            ll lval = lazy[v] * (mid - l), rval = lazy[v] * (r -mid);

            if (lazy[v] > 0) {
                tree[2 * v + 1] = {lval, lval, lval, lval};
                tree[2 * v + 2] = {rval, rval, rval, rval};
            }
            else {
                tree[2 * v + 1] = {0ll, 0ll, 0ll, lval};
                tree[2 * v + 2] = {0ll, 0ll, 0ll, rval};
            }

            lazy[2 * v + 1] = lazy[v];
            lazy[2 * v + 2] = lazy[v];
        } 
        lazy[v] = -LINF;
    }

    void update(int ul, int ur, ll val) {
        auto self = [&](auto&& self, int ul, int ur, ll val, int v, int l, int r) {
            if (l >= ur || r <= ul) return;
            if (ul <= l && r <= ur) {
                ll new_val = val * (r - l);
                if (val > 0) tree[v] = {new_val, new_val, new_val, new_val};
                else tree[v] = {0ll, 0ll, 0ll, new_val};
                lazy[v] = val;
                return;
            }

            push(v, l, r);
            int mid = (l + r) / 2;
            self(self, ul, ur, val, 2 * v + 1, l, mid);
            self(self, ul, ur, val, 2 * v + 2, mid, r);

            ll seg1, seg2, pre1, pre2, suf1, suf2, sum1, sum2, seg, pre, suf, sum;
            tie(seg1, pre1, suf1, sum1) = tree[2 * v + 1];
            tie(seg2, pre2, suf2, sum2) = tree[2 * v + 2];

            seg = max({seg1, seg2, suf1 + pre2});
            pre = max(pre1, sum1 + pre2);
            suf = max(suf2, sum2 + suf1);
            sum = sum1 + sum2;
            tree[v] = {seg, pre, suf, sum};
        };
        self(self, ul, ur, val, 0, 0, N);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    segtree st(n);
    while (m--) {
        int l, r, v; cin >> l >> r >> v;
        st.update(l, r, v);
        cout << get<0>(st.tree[0]) << endl;
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
