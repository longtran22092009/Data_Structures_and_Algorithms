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
    vector <int> tree;

    void init(int n) {
        N = n;
        tree.assign(4*N, 0);
    }

    void build(vector <int> &a) {
        auto self = [&](auto self, int v, int l, int r) {
            if (r - l == 1) {
                tree[v] = a[l];
                return;
            }

            int mid = (l + r) / 2;
            self(self, 2 * v + 1, l, mid);
            self(self, 2 * v + 2, mid, r);

            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        };
        self(self, 0, 0, N);
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

            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        };
        self(self, i, val, 0, 0, N);
    }

    int query(int ql, int qr) {
        auto self = [&](auto self, int ql, int qr, int v, int l, int r) {
            if (l >= qr || r <= ql) return 0;
            if (ql <= l && r <= qr) return tree[v];

            int mid = (l + r) / 2;
            int s1 = self(self, ql, qr, 2 * v + 1, l, mid);
            int s2 = self(self, ql, qr, 2 * v + 2, mid, r);

            return s1 + s2;
        };
        return self(self, ql, qr, 0, 0, N);
    }
};

void solve() {
    int n; cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 != 0) a[i] *= -1;
    }

    segtree st;
    st.init(n);
    st.build(a);

    int m; cin >> m;
    while (m--) {
        int op, i, j;
        cin >> op >> i >> j;
        --i;

        if (op == 0) {
            if (i % 2 != 0) j *= -1;
            st.update(i, j);
        }
        else {
            // [l, r) is 0-based
            --j;
            int ans = st.query(i, j+1);
            if (i % 2 != 0) ans *= -1; // Change the sign
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
