#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

// Tree node v represents [l, r)
struct segtree {
    int N;
    vector <pair <int, int>> tree;

    void init(int n) {
        N = n;
        tree.assign(4*N, {-1, -1});
    }

    pair <int, int> merge(pair <int, int> a, pair <int, int> b) {
        if (a.first < b.first) return a;
        if (a.first > b.first) return b;
        return {a.first, a.second + b.second};
    }

    void build(vector <int> &a) {
        auto self = [&](auto self, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] = {a[l], 1};
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
        auto self = [&](auto self, int i, int val, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] = {val, 1};
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
    
    pair <int, int> query(int ql, int qr) {
        auto self = [&](auto self, int ql, int qr, int v, int l, int r) -> pair <int, int> {
            if (r <= ql || l >= qr) return {INT32_MAX, 0};
            if (ql <= l && r <= qr) return tree[v];
            
            int mid = (l + r) / 2;
            auto p1 = self(self, ql, qr, 2 * v + 1, l, mid);
            auto p2 = self(self, ql, qr, 2 * v + 2, mid, r);

            return merge(p1, p2);
        };
        return self(self, ql, qr, 0, 0, N);
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
        int op, i, v, l, r;
        cin >> op;

        if (op == 1) {
            cin >> i >> v;
            st.update(i, v);
        }
        else {
            cin >> l >> r;
            auto ans = st.query(l, r);

            cout << ans.first << " " << ans.second << endl;
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
