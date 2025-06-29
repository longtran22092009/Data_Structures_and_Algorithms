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
            int mid = (l + r) / 2;
            tree[2 * v + 1] = (mid - l) - tree[2 * v + 1];
            tree[2 * v + 2] = (r - mid) - tree[2 * v + 2];
            // Lat doan [l, r) 2 lan => giu nguyen khong thay doi
            lazy[2 * v + 1] ^= 1;
            lazy[2 * v + 2] ^= 1;
        } 
        lazy[v] = 0;
    }

    void update(int ul, int ur) {
        auto self = [&](auto&& self, int ul, int ur, int v, int l, int r) -> void {
            if (l >= ur || r <= ul) return;
            if (ul <= l && r <= ur) {
                tree[v] = (r - l) - tree[v];
                lazy[v] ^= 1;
                return;
            }

            push(v, l, r);
            int mid = (l + r) / 2;
            self(self, ul, ur, 2 * v + 1, l, mid);
            self(self, ul, ur, 2 * v + 2, mid, r);

            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        };
        self(self, ul, ur, 0, 0, N);
    }

    int query(int k) {
        auto self = [&](auto&& self, int k, int v, int l, int r) -> int {
            if (r - l == 1) return l;

            push(v, l, r);
            int mid = (l + r) / 2;
            int s1 = tree[2 * v + 1];

            if (k < s1)
                return self(self, k, 2 * v + 1, l, mid);
            else 
                return self(self, k - s1, 2 * v + 2, mid, r);
        };
        return self(self, k, 0, 0, N);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    segtree st(n);
    while (m--) {
        int op, l, r, k; cin >> op;

        if (op == 1) {
            cin >> l >> r;
            st.update(l, r);
        }
        else {
            cin >> k;
            cout << st.query(k) << endl;
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
