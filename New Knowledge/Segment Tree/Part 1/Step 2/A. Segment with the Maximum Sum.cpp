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

    void init(int n) {
        N = n;
        tree.assign(4*N, {0ll, 0ll, 0ll, 0ll});
    }

    tuple <ll, ll, ll, ll>  merge(tuple <ll, ll, ll, ll> a, tuple <ll, ll, ll, ll> b) {
        ll seg1, pre1, suf1, sum1, seg2, pre2, suf2, sum2;
        tie(seg1, pre1, suf1, sum1) = a;
        tie(seg2, pre2, suf2, sum2) = b;

        ll seg, pre, suf, sum;
        seg = max({seg1, seg2, suf1 + pre2});
        pre = max(pre1, sum1 + pre2);
        suf = max(suf2, sum2 + suf1);
        sum = sum1 + sum2;

        return {seg, pre, suf, sum};
    }

    void build(vector <ll> &a) {
        auto self = [&](auto self, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] = {max(0ll, a[l]), max(0ll, a[l]), max(0ll, a[l]), a[l]};
                return;
            }

            int mid = (l + r) / 2;
            self(self, 2 * v + 1, l, mid);
            self(self, 2 * v + 2, mid, r);

            tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
        };
        self(self, 0, 0, N);
    }

    void update(int i, ll val) {
        auto self = [&](auto self, int i, ll val, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] = {max(0ll, val), max(0ll, val), max(0ll, val), val};
                return;
            }

            int mid = (l + r) / 2;
            // Nam ben trai
            if (i < mid)
                self(self, i, val, 2 * v + 1, l, mid);
            // Nam ben phai
            else
                self(self, i, val, 2 * v + 2, mid, r);

            tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
        };
        self(self, i, val, 0, 0, N);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vector <ll> a(n);
    for (auto &x : a) cin >> x;

    segtree st;
    st.init(n);
    st.build(a);

    cout << get<0>(st.tree[0]) << endl;
    while (m--) {
        int i; cin >> i;
        ll v; cin >> v;
        
        st.update(i, v);
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
