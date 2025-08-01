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
    vector <ll> tree;
    vector <bool> isLazy;

    segtree (int n) {
        N = n;
        tree.assign(4*N, 0);
        isLazy.assign(4*N, false);
    }

    void push(int v, int l, int r) {
        if (isLazy[v] && r - l > 1) {
            tree[2 * v + 1] = tree[2 * v + 2] = tree[v];
            isLazy[2 * v + 1] = isLazy[2 * v + 2] = true;
        }
        isLazy[v] = false;
    }

    void update(int ul, int ur, int val) {
        auto self = [&](auto&& self, int ul, int ur, int val, int v, int l, int r) -> void {
            if (l >= ur || r <= ul) return;
            if (ul <= l && r <= ur) {
                tree[v] = val;
                isLazy[v] = true;
                return;
            }

            push(v, l, r); // Go deeper -> push down
            int mid = (l + r) / 2;
            self(self, ul, ur, val, 2 * v + 1, l, mid);
            self(self, ul, ur, val, 2 * v + 2, mid, r);
        };
        self(self, ul, ur, val, 0, 0, N);
    }

    ll query(int i) {
        auto self = [&](auto&& self, int i, int v, int l, int r) -> ll {
            if (r - l == 1) return tree[v];
            push(v, l, r); // Go deeper

            int mid = (l + r) / 2;
            if (i < mid)
                return self(self, i, 2 * v + 1, l, mid);
            else
                return self(self, i, 2 * v + 2, mid, r);
        };
        return self(self, i, 0, 0, N);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    segtree st(n);
    while (m--) {
        int op; cin >> op;

        if (op == 1) {
            int l, r, v; cin >> l >> r >> v;
            st.update(l, r, v);
        }
        else {
            int i; cin >> i;
            cout << st.query(i) << endl;
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
