#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 1000005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

struct segtree {
    int N;
    vector <tuple <ll, ll, ll, ll>> tree; // {seg, left, right, sum}
    vector <int> lazy;

    segtree(int n) {
        N = n;
        tree.assign(4*N, tuple <ll, ll, ll, ll>());
        lazy.assign(4*N, -1);
    }

    void push(int v, int l, int r) {
        if (lazy[v] != -1 && r - l > 1) {            
            int mid = (l + r) / 2;
            tree[2 * v + 1] = {lazy[v], lazy[v], lazy[v], lazy[v] * (mid - l)};
            tree[2 * v + 2] = {lazy[v], lazy[v], lazy[v], lazy[v] * (r - mid)};
            lazy[2 * v + 1] = lazy[2 * v + 2] = lazy[v];
        }
        lazy[v] = -1;
    }

    tuple <ll, ll, ll, ll> merge(tuple <ll, ll, ll, ll> &a, tuple <ll, ll, ll, ll> &b) {
        ll seg1, seg2, left1, left2, right1, right2, sum1, sum2, seg, left, right, sum;
        tie(seg1, left1, right1, sum1) = a;
        tie(seg2, left2, right2, sum2) = b;
        // If both segment is 1 (black) => connect two segment together not increasing == seg1 + seg2 - 1
        // Ex: 0011 + 1111 => 00111111 ((2 + 1) => 2 + 1 - 1 = 2)  
        seg = seg1 + seg2 - (right1 == 1 &&left2 == 1); 
        left = left1;
        right = right2;
        sum = sum1 + sum2;
        return {seg, left, right, sum};
    }

    void update(int ul, int ur, int val) {
        auto self = [&](auto&& self, int ul, int ur, int val, int v, int l, int r) -> void {
            if (l >= ur || r <= ul) return;
            if (ul <= l && r <= ur) {
                tree[v] = {val, val, val, val * (r - l)};
                lazy[v] = val;
                return;
            }

            push(v, l, r); // Push down when go deeper
            int mid = (l + r) / 2;
            self(self, ul, ur, val, 2 * v + 1, l, mid);
            self(self, ul, ur, val, 2 * v + 2, mid, r);

            tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
        };
        self(self, ul, ur, val, 0, 0, N);
    }
};

void solve() {
    // White: 0, Black: 1
    int n; cin >> n;

    segtree st(mxN);
    while (n--) {
        char color; cin >> color;
        int c, x, l; cin >> x >> l;
        c = (color == 'B');
        
        x += 500000; // x < 0
        st.update(x, x+l, c);
        cout << get<0>(st.tree[0]) << " " << get<3>(st.tree[0]) << endl;
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
