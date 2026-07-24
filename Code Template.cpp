#include <bits/stdc++.h>
using namespace std;

//====== BITWISE ======//
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define ON(x, i) ((x) | MASK(i))
#define OFF(x, i) ((x) & ~MASK(i))
#define LASTBIT(mask) ((mask) & -(mask))
#define SUBMASK(sub, mask) for (int sub = (mask); sub >= 1; sub = (sub - 1) & (mask))

//====== MISC ======//
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

#define fi first
#define se second
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define compress(c) sort(all(c)); c.erase(unique(all(c)), c.end());
#define Longgggg ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)

inline ll norm(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

inline ll addMod(ll x, ll y, ll m) {
    if (x < 0 || x >= m) x = norm(x, m);
    if (y < 0 || y >= m) y = norm(y, m);

    x += y;
    if (x >= m) x -= m;
    return x;
}

inline ll subMod(ll x, ll y, ll m) {
    if (x < 0 || x >= m) x = norm(x, m);
    if (y < 0 || y >= m) y = norm(y, m);

    x -= y;
    if (x < 0) x += m;
    return x;
}

inline ll mulMod(ll x, ll y, ll m) {
    if (x < 0 || x >= m) x = norm(x, m);
    if (y < 0 || y >= m) y = norm(y, m);

    return x * y % m;
}

//====== FILE ======//
#define NAME "A"
#define IN NAME".in"
#define OUT NAME".out"
#define DEBUG "debug.out"
//#define cerr if (false) cerr
//==================//

const int INF = 2e9+5;
const ll LINF = 4e18;
const ll MOD = 1e9+7;
const int mxN = 1e5+5;

void solve() {

}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }
    Longgggg;

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}

/*
#------ INPUT -------#

#------ OUTPUT ------#

#--------------------#
*/
