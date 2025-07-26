#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 105, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

int n, x;
ll dp[mxN][mxN][5005];

void solve() {
    cin >> n >> x;
    
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin()+1, a.end());
    a[0] = a[1];

    // dp[i][j][k] = số cách chọn đến coder i, có j nhóm đang mở, penalty là k
    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 0; j--) {
            for (int k = x; k >= 0; k--) {
                ll val = dp[i-1][j][k];
                ll newK = k + j * (a[i] - a[i-1]);
                if (newK > x) continue;

                // Giữ nguyên j nhóm chưa hoàn thành, thêm coder i (j cách chọn)
                dp[i][j][newK] = (dp[i][j][newK] + val * (j+1)) % MOD;
                // Tạo nhóm mới chỉ gồm coder i
                if (j+1 <= n) dp[i][j+1][newK] = (dp[i][j+1][newK] + val) % MOD;
                // Hoàn thành nhóm với coder i (j cách chọn)
                if (j-1 >= 0) dp[i][j-1][newK] = (dp[i][j-1][newK] + val * j) % MOD;
            }
        }
    }

    ll res = 0;
    for (int i = 0; i <= x; i++) res = (res + dp[n][0][i]) % MOD;
    cout << res << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();

    // ll a; cin >> a;
    // while (a--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}
