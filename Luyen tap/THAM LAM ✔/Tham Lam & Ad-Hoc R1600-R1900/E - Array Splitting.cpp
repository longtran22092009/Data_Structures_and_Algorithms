#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    // VD: segments {a, b, c}
    // a + b + b + c + c + c = (a + b + c) + (b + c) + c
    // pre[all] + pre[2] + pre[n] + pre[k]
    int n, k; cin >> n >> k;

    vector <int> a(n);
    for (auto &x : a) cin >> x;

    vector <ll> pre(n, a[n-1]);
    for (int i = n-2; i >= 0; i--) pre[i] = pre[i+1] + a[i];
    sort(pre.begin()+1, pre.end(), greater<>());
    // for (auto &x : pre) cout << x << " ";
    // cout << endl;

    ll sum = accumulate(a.begin(), a.end(), 0ll);
    for (int i = 1; i <= k-1; i++) sum += pre[i];

    cout << sum << endl;
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
