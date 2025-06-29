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
    vector<ll> tree, lazy_assign, lazy_add;

    segtree(int n) {
        N = n;
        tree.assign(4*N, 0ll);
        lazy_assign.assign(4*N, -1);
        lazy_add.assign(4*N, 0ll);
    }

    void operation(ll val, int v, int l, int r, int op) {
        if (op == 1) {
            tree[v] = val * (r - l);
            lazy_assign[v] = val;
            lazy_add[v] = 0ll;
        } else {
            tree[v] += val * (r - l);
            lazy_add[v] += val;
        }
    }

    void push(int v, int l, int r) {
        if (r - l == 1) return;
        int mid = (l + r) / 2;
        if (lazy_assign[v] != -1) {
            operation(lazy_assign[v], 2 * v + 1, l, mid, 1);
            operation(lazy_assign[v], 2 * v + 2, mid, r, 1);
        }
        operation(lazy_add[v], 2 * v + 1, l, mid, 2);
        operation(lazy_add[v], 2 * v + 2, mid, r, 2);
        lazy_assign[v] = -1;
        lazy_add[v] = 0ll;
    }

    void update(int ul, int ur, ll val, int op) {
        auto self = [&](auto&& self, int ul, int ur, ll val, int v, int l, int r) -> void {
            push(v, l, r);
            if (l >= ur || r <= ul) return;
            if (ul <= l && r <= ur) {
                operation(val, v, l, r, op);
                return;
            }
            int mid = (l + r) / 2;
            self(self, ul, ur, val, 2 * v + 1, l, mid);
            self(self, ul, ur, val, 2 * v + 2, mid, r);
            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        };
        self(self, ul, ur, val, 0, 0, N);
    }

    ll query(int ql, int qr) {
        auto self = [&](auto&& self, int ql, int qr, int v, int l, int r) -> ll {
            push(v, l, r);
            if (l >= qr || r <= ql) return 0;
            if (ql <= l && r <= qr) return tree[v];

            int mid = (l + r) / 2;
            ll s1 = self(self, ql, qr, 2 * v + 1, l, mid);
            ll s2 = self(self, ql, qr, 2 * v + 2, mid, r);
            return s1 + s2;
        };
        return self(self, ql, qr, 0, 0, N);
    }
};

void solve() {
    
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}