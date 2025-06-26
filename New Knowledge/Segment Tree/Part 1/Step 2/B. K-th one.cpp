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
            
            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        };
        self(self, 0, 0, N);
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
    
    int query(int k) {
        auto self = [&](auto self, int k, int v, int l, int r) -> int {
            if (r - l == 1) return l;
            
            int sl = tree[2 * v + 1], sr = tree[2 * v + 2];
            int mid = (l + r) / 2;

            if (k < sl) 
                return self(self, k, 2 * v + 1, l, mid);
            else 
                return self(self, k - sl, 2 * v + 2, mid, r);
        };
        return self(self, k, 0, 0, N);
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
        int op, i, k;
        cin >> op;

        if (op == 1) {
            cin >> i;
            st.update(i);
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
