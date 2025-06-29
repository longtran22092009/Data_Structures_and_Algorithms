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
    vector <int> tree, lazy;

    segtree(int n) {
        N = n;
        tree.assign(4*N, 0);
        lazy.assign(4*N, 0);
    }

    void push(int v, int l, int r) {
        if (lazy[v] && r - l > 1) {
            tree[2 * v + 1] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
            
            tree[2 * v + 2] += lazy[v];
            lazy[2 * v + 2] += lazy[v];
        } 
        lazy[v] = 0;
    }

    void update(int ul, int ur, int val) {
        auto self = [&](auto&& self, int ul, int ur, int val, int v, int l, int r) -> void {
            if (l >= ur || r <= ul) return;
            if (ul <= l && r <= ur) {
                tree[v] += val;
                lazy[v] += val;
                return;
            }

            push(v, l, r);
            int mid = (l + r) / 2;
            self(self, ul, ur, val, 2 * v + 1, l, mid);
            self(self, ul, ur, val, 2 * v + 2, mid, r);

            tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
        };
        self(self, ul, ur, val, 0, 0, N);
    }

    int query(int x, int ql) {
        auto self = [&](auto&& self, int x, int ql, int v, int l, int r) -> int {
            if (r <= ql || tree[v] < x) return -1;
            if (r - l == 1) return l;

            push(v, l, r);
            int mid = (l + r) / 2;
            int s1 = self(self, x, ql, 2 * v + 1, l, mid);

            if (s1 != -1) return s1;
            return self(self, x, ql, 2 * v + 2, mid, r);
        };
        return self(self, x, ql, 0, 0, N);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    segtree st(n);
    while (m--) {
        int op, l, r, v, x; cin >> op;

        if (op == 1) {
            cin >> l >> r >> v;
            st.update(l, r, v);
        }
        else {
            cin >> x >> l;
            cout << st.query(x, l) << endl;
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
