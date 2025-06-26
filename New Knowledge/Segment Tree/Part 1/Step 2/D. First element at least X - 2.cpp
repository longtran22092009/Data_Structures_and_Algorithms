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
        auto self = [&](auto self, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] = a[l];
                return;
            }

            int mid = (l + r) / 2;
            self(self, 2 * v + 1, l, mid);
            self(self, 2 * v + 2, mid, r);

            tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
        };
        self(self, 0, 0, N);
    }

    void update(int i, int val) {
        auto self = [&](auto self, int i, int val, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] = val;
                return;
            }

            int mid = (l + r) / 2;
            if (i < mid) 
                self(self, i, val, 2 * v + 1, l, mid);
            else
                self(self, i, val, 2 * v + 2, mid, r);

            tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
        };
        self(self, i, val, 0, 0, N);
    }

    // Index of first element >= x in [l, n)
    int query(int x, int ql) {
        auto self = [&](auto self, int x, int v, int l, int r) -> int {
            if (tree[v] < x) return -1; // Không có giá trị nào >= x ở node này
            if (r <= ql) return -1;
            if (r - l == 1) return l;
    
            int mid = (l + r) / 2;
            int res = self(self, x, 2 * v + 1, l, mid);
            if (res != -1) return res;
            return self(self, x, 2 * v + 2, mid, r);
        };
        return self(self, x, 0, 0, N);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    segtree st;
    st.init(n);
    st.build(a);

    while (m--) {
        int op, i, val, x, l;
        cin >> op;

        if (op == 1) {
            cin >> i >> val;
            st.update(i, val);
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
