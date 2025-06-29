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
    vector <ll> lazy1; // Store the sum of a + (d * l)
    vector <ll> lazy2; // Store the sum of d for d * i

    segtree(int n) {
        N = n;
        lazy1.assign(4*N, 0ll);
        lazy2.assign(4*N, 0ll);
    }

    void push(int v, int l, int r) {
        if (r - l == 1) return;

        int mid = (l + r) / 2;
        lazy1[2 * v + 1] += lazy1[v];
        lazy2[2 * v + 1] += lazy2[v];

        lazy1[2 * v + 2] += lazy1[v];
        lazy2[2 * v + 2] += lazy2[v];

        lazy1[v] = lazy2[v] = 0ll;
    }

    void update(ll ul, ll ur, ll a, ll d) {
        auto self = [&](auto&& self, ll ul, ll ur, ll a, ll d, int v, int l, int r) -> void{
            if (l >= ur || r <= ul) return;
            if (ul <= l && r <= ur) {
                lazy1[v] += a - d * ul;
                lazy2[v] += d;
                return;
            }

            push(v, l, r);
            int mid = (l + r) / 2;
            self(self, ul, ur, a, d, 2 * v + 1, l, mid);
            self(self, ul, ur, a, d, 2 * v + 2, mid, r);
        };
        self(self, ul, ur, a, d, 0, 0, N);
    }
    
    ll query(int i) {
        auto self = [&](auto&& self, int i, int v, int l, int r) -> ll {
            if (r - l == 1) return lazy1[v] + lazy2[v] * i; // a - d*l + d*i
            
            push(v, l, r);
            int mid = (l + r) / 2;
            if (i < mid) return self(self, i, 2 * v + 1, l, mid);
            else return self(self, i, 2 * v + 2, mid, r);
        };
        return self(self, i, 0, 0, N);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    segtree st(n);
    while (m--) {
        int op; cin >> op;

        if (op == 1) {
            // For each element i in range [l, r] += a + d * (i - l)
            ll l, r, a, d; cin >> l >> r >> a >> d;
            st.update(l-1, r, a, d);
        }
        else {
            // Get the element i
            int i; cin >> i;
            cout << st.query(i-1) << endl;
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
