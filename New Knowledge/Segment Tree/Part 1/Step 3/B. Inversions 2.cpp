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

    void build() {
        auto self = [&](auto self, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] = 1;
                return;
            }

            int mid = (l + r) / 2;
            self(self, 2 * v + 1, l, mid);
            self(self, 2 * v + 2, mid, r);

            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        };
        self(self, 0, 0, N);
    } 

    void update(int i) {
        auto self = [&](auto self, int i, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] = 0;
                return;
            }

            int mid = (l + r) / 2;
            if (i < mid) 
                self(self, i, 2 * v + 1, l, mid);
            else
                self(self, i, 2 * v + 2, mid, r);

            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        };
        self(self, i, 0, 0, N);
    }

    int query(int k) {
        auto self = [&](auto self, int k, int v, int l, int r) -> int {
            if (r - l == 1) return l;

            int mid = (l + r) / 2;
            int sl = tree[2 * v + 1], sr = tree[2 * v + 2];

            if (k < sr) 
                return self(self, k, 2 * v + 2, mid, r);
            else
                return self(self, k - sr, 2 * v + 1, l, mid);
        };
        return self(self, k, 0, 0, N);
    }
};

void solve() {
    int n; cin >> n;

    vector <int> a(n), res(n);
    for (auto &x : a) cin >> x;

    segtree st;
    st.init(n);
    st.build();

    for (int i = n-1; i >= 0; i--) {
        int k = a[i], node = st.query(k);
        res[i] = node + 1;
        st.update(node);
    }

    for (auto &x : res) cout << x << " ";
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
