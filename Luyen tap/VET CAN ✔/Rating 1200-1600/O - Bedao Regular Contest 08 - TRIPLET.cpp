#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    int n, k; cin >> n >> k;
    // k lẻ => a, b, c phải cùng chia hết cho k 
    ll num = n/k, ans = 1ll * num * num * num;
    // k chẵn => a, b, c phải cùng chia hết cho k 
    // hoặc mod k = k/2 vì a+b = k và a+c = k => a, b, c = k/2 
    if (k % 2 == 0) {
        // Mỗi k số sẽ có 1 số k/2
        ll num2 = (n + k/2) / k;
        ans += 1ll * num2 * num2 * num2; // Tính cả tổ hợp 3 số
    }

    cout << ans << endl;
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
