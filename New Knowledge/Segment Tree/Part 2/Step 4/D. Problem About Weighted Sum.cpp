#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

// Sum [l, r] = (r - l + 1) * (l + r) / 2 (Total element * (first element + last element) / 2)
struct segtree {
    int N;
    vector <ll> tree, sum, lazy;

    segtree(int n) {
        N = n;
        tree.assign(4*N, 0ll);
        sum.assign(4*N, 0ll);
        lazy.assign(4*N, 0);
    }

    void build(vector <ll> &a) {
        auto self = [&](auto&& self, int v, int l, int r) {
            if (r - l == 1) {
                tree[v] = a[l] * (l + 1);
                sum[v] = a[l];
                return;
            }
            
            int mid = (l + r) / 2;
            self(self, 2 * v + 1, l, mid);
            self(self, 2 * v + 2, mid, r);
            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
            sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
        };
        self(self, 0, 0, N);
    }

    void push(int v, int l, int r) {
        if ( r - l > 1) {
            int mid = (l + r) / 2;
            tree[2 * v + 1] += lazy[v] * (1ll * (mid - l) * (l + 1 + mid) / 2);
            tree[2 * v + 2] += lazy[v] * (1ll * (r - mid) * (mid + 1 + r) / 2);
            
            sum[2 * v + 1] += lazy[v] * (mid - l);
            sum[2 * v + 2] += lazy[v] * (r - mid);

            lazy[2 * v + 1] += lazy[v]; 
            lazy[2 * v + 2] += lazy[v]; 
        }
        lazy[v] = 0;
    }

    void update(int ul, int ur, ll val) {
        auto self = [&](auto&& self, int ul, int ur, ll val, int v, int l, int r) -> void {
            if (l >= ur || r <= ul) return;
            if (ul <= l && r <= ur) {
                tree[v] += val * (1ll * (r - l) * (l + 1 + r) / 2);
                sum[v] += val * (r - l);
                lazy[v] += val;
                return;
            }

            push(v, l, r);
            int mid = (l + r) / 2;
            self(self, ul, ur, val, 2 * v + 1, l, mid);
            self(self, ul, ur, val, 2 * v + 2, mid, r);

            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
            sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
        };
        self(self, ul, ur, val, 0, 0, N);
    }

    ll query(int ql, int qr) {
        auto self = [&](auto&& self, int ql, int qr, int v, int l, int r) -> ll {
            if (l >= qr || r <= ql) return 0;
            if (ql <= l && r <= qr) return tree[v] - sum[v] * ql;
            
            push(v, l, r);
            int mid = (l + r) / 2;
            ll s1 = self(self, ql, qr, 2 * v + 1, l, mid);
            ll s2 = self(self, ql, qr, 2 * v + 2, mid, r);

            return s1 + s2;
        };
        return self(self, ql, qr, 0, 0, N);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vector <ll> a(n);
    for (auto &x : a) cin >> x;

    segtree st(n);
    st.build(a);

    while (m--) {
        int op, l, r, d; cin >> op >> l >> r;

        if (op == 1) {
            cin >> d;
            st.update(l-1, r, d);
        }
        else {
            cout << st.query(l-1, r) << endl;
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
