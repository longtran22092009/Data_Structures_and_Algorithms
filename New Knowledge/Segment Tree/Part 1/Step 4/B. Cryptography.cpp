#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

// Tree node v represents [l, r) in 0-based index
struct segtree {
    int N, Mod;
    vector <array <array <ll, 2>, 2>> tree;

    void init(int n, int mod) {
        N = n;
        Mod = mod;
        tree.assign(4*N, {{{0ll, 0ll}, {0ll, 0ll}}});
    }

    array <array <ll, 2>, 2> mul(array <array <ll, 2>, 2> &a, array <array <ll, 2>, 2> &b, int Mod) {
        array <array <ll, 2>, 2> res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % Mod;
                }
            }
        }
        return res;
    }

    void build(vector <array <array <ll, 2>, 2>> &a) {
        auto self = [&](auto self, int v, int l, int r) {
            if (r - l == 1) {
                tree[v] = a[l];
                return;
            }

            int mid = (l + r) / 2;
            self(self, 2 * v + 1, l, mid);
            self(self, 2 * v + 2, mid, r);

            tree[v] = mul(tree[2 * v + 1], tree[2 * v + 2], Mod);
        };
        self(self, 0, 0, N);
    }

    array <array <ll, 2>, 2> query(int ql, int qr) {
        auto self = [&](auto self, int ql, int qr, int v, int l, int r) -> array <array <ll, 2>, 2> {
            if (l >= qr || r <= ql) return {{{1, 0}, {0, 1}}}; // Ma tran don vi
            if (ql <= l && r <= qr) return tree[v];

            int mid = (l + r) / 2;
            array <array <ll, 2>, 2> s1, s2;
            s1 = self(self, ql, qr, 2 * v + 1, l, mid);
            s2 = self(self, ql, qr, 2 * v + 2, mid, r);

            return mul(s1, s2, Mod);
        };
        return self(self, ql, qr, 0, 0, N);
    }
};

void solve() {
    ll mod; cin >> mod;
    ll n, m; cin >> n >> m;

    vector <array <array <ll, 2>, 2>> a(n);
    for (int i = 0; i < n; i++) {
        int b, c, d, e; cin >> b >> c >> d >> e;
        a[i] = {{{b, c}, {d, e}}};
    }

    segtree st;
    st.init(n, mod);
    st.build(a);

    while (m--) {
        int x, y; cin >> x >> y;
        array <array <ll, 2>, 2> ans = st.query(x-1, y);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) cout << ans[i][j] << " ";
            cout << endl;
        }
        cout << endl << endl;
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
