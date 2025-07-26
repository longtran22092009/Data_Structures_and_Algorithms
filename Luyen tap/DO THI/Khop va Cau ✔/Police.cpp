#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    # Truy vấn 1:
        Nếu num[u] <= num[v] <= tail[u] thì đỉnh v thuộc cây con gốc u của cây DFS
        (thứ tự duyệt đỉnh v trong khoảng [tgian bắt đầu duyệt đỉnh u, tgian kết thúc duyệt đỉnh u])
    # Truy vấn 2:
        Xóa khớp C:
        1. Các tplt có gốc v là con trực tiếp của C (low[v] >= num[C]) (nốt lá của C trở xuống)
        2. Các tplt có gốc u là con trực tiếp của C (low[u] < num[C]) (nốt cha của C trở lên)
*/

const int mxN = 100005, INF = (int) 1e9+5;
int n, m, Q;
vector <int> adj[mxN];

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> Q;
    while (Q--) {
        int type, A, B, C, G1, G2;
        cin >> type;

        if (type == 1) {
            cin >> A >> B >> G1 >> G2;
        }
        else if (type == 2) {
            cin >> A >> B >> C;
        }
    }
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}
