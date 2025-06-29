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
    // lazy store the adding val to that segment

    segtree (int n) {
        N = n;
        tree.assign(4*N, 1ll);
        lazy.assign(4*N, 1ll);
    }

    void build() {
        auto self = [&](auto&& self, int v, int l, int r) {
            if (r - l == 1) return;
            
            int mid = (l + r) / 2;
            self(self, 2 * v + 1, l, mid);
            self(self, 2 * v + 2, mid, r);

            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        };
        self(self, 0, 0, N);
    }

    void push(int v, int l, int r) {
        if (r - l > 1) {
            tree[2 * v + 1] = (tree[2 * v + 1] % MOD) * (lazy[v] % MOD);
            lazy[2 * v + 1] = (lazy[2 * v + 1] % MOD) * (lazy[v] % MOD);

            tree[2 * v + 2] = (tree[2 * v + 2] % MOD) * (lazy[v] % MOD);
            lazy[2 * v + 2] = (lazy[2 * v + 2] % MOD) * (lazy[v] % MOD);
        }
        lazy[v] = 1;
    }

    void update(int ul, int ur, int val) {
        auto self = [&](auto&& self, int ul, int ur, int val, int v, int l, int r) -> void {
            if (l >= ur || r <= ul) return;
            if (ul <= l && r <= ur) {
                tree[v] = (tree[v] % MOD) * (val % MOD);
                lazy[v] = (lazy[v] % MOD) * (val % MOD);
                return;
            }

            push(v, l, r); // Push down to go deeper
            int mid = (l + r) / 2;
            self(self, ul, ur, val, 2 * v + 1, l, mid);
            self(self, ul, ur, val, 2 * v + 2, mid, r);
            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
            tree[v] %= MOD;
        };
        self(self, ul, ur, val, 0, 0, N);
    }

    ll query(int ql, int qr) {
        auto self = [&](auto&& self, int ql, int qr, int v, int l, int r) -> ll {
            if (l >= qr || r <= ql) return 0;
            if (ql <= l && r <= qr) return tree[v];

            push(v, l, r); // Push down to go deeper
            int mid = (l + r) / 2;
            ll s1 = self(self, ql, qr, 2 * v + 1, l, mid);
            ll s2 = self(self, ql, qr, 2 * v + 2, mid, r);
            return (s1 + s2) % MOD;
        };
        return self(self, ql, qr, 0, 0, N) % MOD;
    }
};

void solve() {
    int n, m; cin >> n >> m;

    segtree st(n);
    st.build();
    
    while (m--) {
        int op; cin >> op;

        if (op == 1) {
            int l, r, v; cin >> l >> r >> v;
            st.update(l, r, v);
        }
        else {
            int l, r; cin >> l >> r;
            cout << st.query(l, r) << endl;
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
