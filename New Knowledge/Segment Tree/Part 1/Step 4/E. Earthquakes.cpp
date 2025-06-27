#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 40, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

// Tree node v represents [l, r) in 0-based index
struct segtree {
    int N;
    vector <int> tree;

    segtree(int n) {
        N = n;
        tree.assign(4*N, INF);
    }

    void update(int i, int val) {
        auto self = [&](auto self, int i, int val, int v, int l, int r) {
            if (r - l == 1) {
                tree[v] = val;
                return;
            }

            int mid = (l + r) / 2;
            if (i < mid)
                self(self, i, val, 2 * v + 1, l, mid);
            else
                self(self, i, val, 2 * v + 2, mid, r);

            tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
        };
        self(self, i, val, 0, 0, N);
    }

    int query(int ql, int qr, int p) {
        auto self = [&](auto self, int ql, int qr, int p, int v, int l, int r) {
            if (l >= qr || r <= ql) return 0;
            if (r - l == 1) {
                if (tree[v] <= p) {
                    tree[v] = INF;
                    return 1;
                }
                return 0;
            }

            int mid = (l + r) / 2;
            int mnl = tree[2 * v + 1], mnr = tree[2 * v + 2], s1 = 0, s2 = 0;
            if (mnl <= p) s1 = self(self, ql, qr, p, 2 * v + 1, l, mid);
            if (mnr <= p) s2 = self(self, ql, qr, p, 2 * v + 2, mid, r);

            tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
            return s1 + s2;
        };
        return self(self, ql, qr, p, 0, 0, N);
    }
};

void solve() {
    int n, Q;
    cin >> n >> Q;
    segtree st(n);

    while (Q--) {
        int op, i, h, l, r, p;
        cin >> op;

        if (op == 1) {
            cin >> i >> h;
            st.update(i, h);
        } else {
            cin >> l >> r >> p;
            cout << st.query(l, r, p) << endl;
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