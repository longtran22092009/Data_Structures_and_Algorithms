#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"

const int mxN = 100005, INF = (int) 1e9+5;
string s;
double P;

void init() {
    cin >> s;
    int len = s.size();
    for (int i = 0; i < min(20, len); i++) { // double precision: 15-16 digit
        P = P * 10 + (s[i] - '0');
    }
    P = log10(P) + (len - min(20, len));
}

void solve() {
    // Log(P) = log(X) + log(X+1) + ... + log(Y)
    init();

    int l = 1;
    double sum = 0.0;
    for (int r = 1; r <= 100000; r++) {
        sum += log10(r);
        while (l <= r && sum > P + 1e-9) sum -= log10(l++); // EPS = 1e-9
        if (fabs(P - sum) <= 1e-9) {
            cout << l << " " << r << endl;
            return;
        }
    }
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    // ll t; cin >> t;
    // while (t--)
    solve();
}