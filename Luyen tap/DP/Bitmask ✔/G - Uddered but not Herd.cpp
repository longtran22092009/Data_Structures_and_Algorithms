#include <bits/stdc++.h>
using namespace std;
//====== BITWISE ======//
#define MASK(i) (1LL << (i))
#define BIT(x, i) (1LL & ((x) >> (i)))
#define ON(x, i) ((x) | MASK(i))
#define OFF(x, i) ((x) & ~MASK(i))
#define LASTBIT(mask) ((mask) & -(mask))
#define SUBMASK(sub, mask) for (int sub = (mask); sub >= 1; sub = (sub - 1) & (mask))
//====== OTHER ======//
#define fi first
#define se second
#define ll long long
#define endl '\n'
#define all(x) begin(x), end(x)
#define mod(x, k) ((((x) % (k)) + (k)) % (k))
#define compress(c) sort(all(c)); c.erase(unique(all(c)), c.end());
#define Longgggg ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
//====== FILE ======//
#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"
//==================//

const int INF = (int) 1e9+5;
const ll LINF = (ll) 1e18;
const ll MOD = (ll) 1e9+7;
const int mxN = 20;

string s;
map <char, int> a;
int dp[MASK(mxN)];
int f[mxN][mxN];

void solve() {
    cin >> s;
    for (auto &si : s) a[si] = -1;
    
    int num = 0;
    for (auto &si : s) if (a[si] < 0) a[si] = num, num++;
    FOR(i, 0, (int)s.size()-2) f[a[s[i]]][a[s[i+1]]]++;

    memset(dp, INF, sizeof(dp));
    dp[0] = 1;
    FOR(mask, 1, MASK(num)-1) FOR(i, 0, num-1) if (BIT(mask, i)) {
        // From alphabet lst, add a[i] to the back of tha mask alphabet
        // -> +1 cycle for each pair (x, i) in lst and (i,i) - itself
        int lst = OFF(mask, i), sum = f[i][i];
        FOR(j, 0, num-1) if (BIT(lst, j)) sum += f[j][i];
        dp[mask] = min(dp[mask], dp[lst] + sum);
    }

    cout << dp[MASK(num)-1] << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }
    Longgggg

    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
