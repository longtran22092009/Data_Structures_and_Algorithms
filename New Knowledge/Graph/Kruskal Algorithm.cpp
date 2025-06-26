#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


/*
    # Kruskal Algorithm (Tìm cây khung nhỏ nhất)
    # Minimum Spanning Tree (MST) 

        ## Cây khung là gì ##
    Có n đỉnh và đúnh n-1 cạnh (Đồ thị vô hướng)
    Mỗi cạnh có thêm trọng số

    * Bước 1: Khởi tạo
        MST = {} // Cây khung rỗng
        d[MST] = 0; // Trọng số của cây khung bằng 0
    * Bước 2: Sắp xếp
        sort(các cạnh theo chiều dài tăng dần)
    * Bước 3: Lặp
        while (số cạnh của cây khung < n-1 && tập cạnh != rỗng) {
            e = cạnh ngắn nhất;
            E.erase(e); // Có thể bỏ qua
            if (MST cho thêm cạnh e vào không tạo thành chu trình) { // Sử dụng DSU
                MST thêm cạnh e;
                d[MST] += d[e];
            }
        }

    VD: 6 9
        1 2 12
        1 3 4
        2 3 1
        2 4 5
        2 5 3
        3 5 2
        4 5 3
        4 6 10
        5 6 8
        
    =>  MST: 18
        2 3: 1
        3 5: 2
        4 5: 3
        1 3: 4
        5 6: 8
*/

struct Edge {
    int u, v, w;
};

const int mxN = 10005;
int n, m;
int par[mxN], sz[mxN];
vector <Edge> edges;

void make_set() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false; // a, b đã có trong cây khung (tạo thành chu trình nếu gộp lại)
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

void Kruskal() {
    // 1. Tạo MST rỗng
    vector <Edge> MST;
    int d = 0; // Trọng số của MST
    // 2. Sort cạnh theo thứ tự tăng dần
    sort(edges.begin(), edges.end(), [&](Edge &a, Edge &b) { return a.w < b.w; });
    // 3. Lặp
    for (int i = 0; i < m; i++) {
        if (MST.size() == n-1) break; // Đã xây xong cây khung
        Edge e = edges[i];
        if (Union(e.u, e.v)) {
            MST.push_back(e);
            d += e.w;
        }
    }
    // 4. Trả về kết quả
    if (MST.size() != n-1) {
        cout << "Đồ thị không liên thông (Không tồn tại cây khung)\n";
    }
    else {
        cout << "MST: " << d << endl;
        for (auto &x : MST) cout << x.u << " "  << x.v << ": " << x.w << endl; 
    }
}

void solve() {
    // n đỉnh, m cạnh
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y, w; cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    make_set();
    Kruskal();
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
