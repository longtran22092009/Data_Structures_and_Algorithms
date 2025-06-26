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

    void update(int i) {
        auto self = [&](auto self, int i, int v, int l, int r) -> void {
            if (r - l == 1) {
                tree[v] ^= 1;
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

    int query(int ql, int qr) {
        auto self = [&](auto self, int ql, int qr, int v, int l, int r) -> int {
            if (r <= ql || l >= qr) return 0;
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

    vector <int> a(2*n), pos(n+1, -1), res(n+1, 0);
    for (auto &x : a) cin >> x;

    segtree st;
    st.init(2*n);

    // Left to right check intersect with right border
    for (int i = 0; i < 2*n; i++) {
        int x = a[i];
        if (pos[x] == -1) {
            pos[x] = i; // Left-end position
            st.update(i);
        }
        else {
            int l = pos[x], r = i;
            res[x] += st.query(l+1, r);
            st.update(l);
        }
    }
    
    // Right to left check intersect with left border
    st.init(2*n);
    fill(pos.begin(), pos.end(), -1);
    reverse(a.begin(), a.end());
    
    for (int i = 0; i < 2*n; i++) {
        int x = a[i];
        if (pos[x] == -1) {
            pos[x] = i; // Left-end position
            st.update(i);
        }
        else {
            int l = pos[x], r = i;
            res[x] += st.query(l+1, r);
            st.update(l);
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << " ";
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
