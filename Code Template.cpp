#include <bits/stdc++.h>
using namespace std;
//====== BITWISE ======//
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define ON(x, i) ((x) | MASK(i))
#define OFF(x, i) ((x) & ~MASK(i))
#define LASTBIT(mask) ((mask) & -(mask))
#define SUBMASK(sub, mask) for (ll sub = (mask); sub >= 1; sub = (sub - 1) & (mask))
//====== OTHERS ======//
#define ll long long
#define fi first
#define se second
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define compress(c) sort(all(c)); c.erase(unique(all(c)), c.end());
#define Longgggg ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)

template <typename T>
inline T modulo(T x, T k) {
    T res = x % k;
    return (res < 0) ? (res + k) : res;
}
//====== FILE ======//
#define NAME "A"
#define IN NAME".in"
#define OUT NAME".out"
#define DEBUG "debug.out"
//#define cerr if (false) cerr
//==================//

const int INF = 1e9+5;
const ll LINF = 1e18;
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
