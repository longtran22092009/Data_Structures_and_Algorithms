#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


// Disjoint Set Union (DSU) || Union Find
const int mxN = 10005;
int n;
int par[mxN], sizes[mxN];

void make_set() {
    for (int i = 1; i <= n; i++) par[i] = i;
}
// O(a(n)) - a(n): Inverse Ackermann function (grows extremely slowly)
int find(int v) {
    if (v == par[v]) return v;
    par[v] = find(par[v]); // Path compression optimization
    return par[v];
}
// O(a(n)) - a(n): Inverse Ackermann function (grows extremely slowly)
void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (sizes[a] < sizes[b]) swap(a, b);
        par[b] = a;
        sizes[a] += sizes[b];
    }
}

void solve() {
    cin >> n;
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