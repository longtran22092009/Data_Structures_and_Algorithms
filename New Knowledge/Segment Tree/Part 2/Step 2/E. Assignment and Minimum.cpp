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
    vector <ll> tree, lazy;

    segtree(int n) {
        N = n;
        tree.assign(4*N, 0ll);
        lazy.assign(4*N, -1);
    }

    void push(int v, int l, int r) {
        if (lazy[v] != -1 && r - l > 1) {
            tree[2 * v + 1] = lazy[v];
            lazy[2 * v + 1] = lazy[v];
            
            tree[2 * v + 2] = lazy[v];
            lazy[2 * v + 2] = lazy[v];
        }
        lazy[v] = -1;
    }

    void update(int ul, int ur, ll val) {
        auto self = [&](auto&& self, int ul, int ur, ll val, int v, int l, int r) -> void {
            if (l >= ur || r <= ul) return;
            if (ul <= l && r <= ur) {
                tree[v] = val;
                lazy[v] = val;
                return;
            }

            push(v, l, r);
            int mid = (l + r) / 2;
            self(self, ul, ur, val, 2 * v + 1, l, mid);
            self(self, ul, ur, val, 2 * v + 2, mid, r);

            tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
        };
        self(self, ul, ur, val, 0, 0, N);
    }

    ll query(int ql, int qr) {
        auto self = [&](auto&& self, int ql, int qr, int v, int l, int r) -> ll {
            if (l >= qr || r <= ql) return LINF;
            if (ql <= l && r <= qr) return tree[v];
            
            push(v, l, r);
            int mid = (l + r) / 2;
            ll s1 = self(self, ql, qr, 2 * v + 1, l, mid);
            ll s2 = self(self, ql, qr, 2 * v + 2, mid, r);

            return min(s1, s2);
        };
        return self(self, ql, qr, 0, 0, N);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    segtree st(n);
    while (m--) {
        int op, l, r, v;
        cin >> op >> l >> r;

        if (op == 1) {
            cin >> v;
            st.update(l, r, v);
        }
        else cout << st.query(l, r) << endl;
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
