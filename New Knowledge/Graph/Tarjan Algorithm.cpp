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
int bridge = 0; // Số lượng cạnh cầu
int num[mxN], low[mxN]; // low[u] cho biết nốt u thuộc cây DFS gốc low[u]
bool joint[mxN]; // Đánh dấu đỉnh khớp
vector <int> adj[mxN];

// Cây con DFS: Đoạn các node có gốc u có thể tới trực tiếp các nốt v khác
// Từ nốt u ra các nốt lá v thì mỗi nốt lá đó thuộc một cây khác nhau (Rẽ nhánh -> cây DFS mới) 
// a -> b -> c là một cây DFS
// a -> b -> c và b -> d thì d không thuộc cây DFS có gốc a mà thuộc cây DFS có gốc b

void dfs(int u, int pre) {
    int child = 0;
    num[u] = low[u] = ++timeDfs;

    for (int &v : adj[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) ++bridge; // Hai node có thể đến với nhau không qua nét đứt
            ++child;
            
            if (u == pre) {
                if (child > 1) joint[u] = true; // Nếu u là gốc của cây DFS và có hơn 1 nốt con
            }
            else if (low[v] >= num[u]) joint[u] = true; // v là con trực tiếp của u
        }
        else low[u] = min(low[u], num[v]);
    }
}

void solve() {
    // n đỉnh, m cạnh
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!num[i]) dfs(i, i);
    }

    int cntJoint = 0;
    for (int i = 1; i <= n; i++) cntJoint += joint[i];

    cout << cntJoint << " " << bridge << endl;
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
