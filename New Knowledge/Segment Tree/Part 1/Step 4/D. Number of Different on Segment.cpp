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
    vector <vector <int>> tree;

    segtree(int n) {
        N = n;
        tree.assign(4*N, vector <int>(mxN+1, 0));
    }

    vector <int> merge(vector <int> &a, vector <int> &b) {
        vector <int> res(mxN+1, 0);
        for (int i = 1; i <= mxN; i++) res[i] = a[i] + b[i];
        return res;
    }

    void build(vector <int> &a) {
        auto self = [&](auto self, int v, int l, int r) {
            if (r - l == 1) {
                tree[v][a[l]] = 1;
                return;
            }

            int mid = (l + r) / 2;
            self(self, 2 * v + 1, l, mid);
            self(self, 2 * v + 2, mid, r);

            tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
        };
        self(self, 0, 0, N);
    }

    void update(int i, int val) {
        auto self = [&](auto self, int i, int val, int v, int l, int r) {
            if (r - l == 1) {
                fill(tree[v].begin(), tree[v].end(), 0);
                tree[v][val] = 1;
                return;
            }

            int mid = (l + r) / 2;
            if (i < mid)
                self(self, i, val, 2 * v + 1, l, mid);
            else
                self(self, i, val, 2 * v + 2, mid, r);

            tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
        };
        self(self, i, val, 0, 0, N);
    }

    vector <int> query(int ql, int qr) {
        auto self = [&](auto self, int ql, int qr, int v, int l, int r) {
            if (l >= qr || r <= ql) return vector <int> (mxN+1, 0);
            if (ql <= l && r <= qr) return tree[v];

            int mid = (l + r) / 2;
            vector <int> s1, s2;
            s1 = self(self, ql, qr, 2 * v + 1, l, mid);
            s2 = self(self, ql, qr, 2 * v + 2, mid, r);
            return merge(s1, s2);
        };
        return self(self, ql, qr, 0, 0, N);
    }
};

void solve() {
    int n, Q; cin >> n >> Q;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    segtree st(n);
    st.build(a);

    while (Q--) {
        int op, x, y; cin >> op >> x >> y;

        if (op == 1) {
            vector <int> res = st.query(x-1, y);
            int ans = 0;
            for (int i = 1; i <= mxN; i++) ans += res[i] != 0;
            cout << ans << endl;
        }
        else st.update(x-1, y);
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