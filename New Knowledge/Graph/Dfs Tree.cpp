#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    # Tarjan Algorithm (Kiểm tra đỉnh trụ và cạnh cầu)
    Đỉnh trụ: Khi loại bỏ đỉnh này sẽ làm tăng thành phần liên thông 
    Cạnh cầu: Khi loại bỏ cạnh này sẽ làm tăng thành phần liên thông 

    num[u]: thứ tự duyệt của đỉnh u
    low[u]: giá trị num nhỏ nhât có thể đi đến
    (xuôi theo cạnh nét liền (cung) của cây DFS và ngược lên không quá 1 cạnh nét đứt)
    tail[u]: thời gian kết thúc duyệt DFS của đỉnh u
*/


const int mxN = 10005;
int n, m;
int timeDfs = 0; // Thứ tự duyệt DFS
int num[mxN], low[mxN], tail[mxN];
vector <int> adj[mxN];

void dfs(int u, int pre) {
    num[u] = low[u] = ++timeDfs;

    for (auto &v : adj[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[u]);
    }
    tail[u] = timeDfs;
}

void solve() {
    // n đỉnh, m cạnh
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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
