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
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define fi first
#define se second
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define compress(c) sort(all(c)); c.erase(unique(all(c)), c.end());
#define Longgggg ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)

template <typename T>
inline T modulo(T x, T k) {
    T res = x % k;
    return (res < 0) ? (res + k) : res;
}

template <typename T>
inline T addMod(T x, T y, T m) {
    x = modulo(x, m);
    y = modulo(y, m);

    return (x >= m - y ? x - m + y : x + y);
}

template <typename T>
inline T subMod(T x, T y, T m) {
    x = modulo(x, m);
    y = modulo(y, m);

    T res = x - y;
    return (res < 0 ? res + m : res);
}

template <typename T>
inline T mulMod(T x, T y, T m) {
    x = modulo(x, m);
    y = modulo(y, m);

    return (T)((__int128)x * y % m);
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
