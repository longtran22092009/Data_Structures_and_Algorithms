#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


vector <string> S = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Aa", "Bb", "Cc", "Dd", "Ee", "Ff", "Gg", "Hh", "Ii", "Jj", "Kk", "Ll", "Mm", "Nn", "Oo", "Pp", "Qq", "Rr", "Ss", "Tt", "Uu", "Vv", "Ww", "Xx", "Yy", "Zz"};

void solve() {
    ll n, k; cin >> n >> k;
    
    vector <ll> good(n-k+1);
    for (ll i = 0; i < n-k+1; i++) {
        string x; cin >> x;
        good[i] = (x == "YES")? 1 : 0;
    }
    
    // for (auto &x : good) cout << x << " ";
    // cout << endl;
    
    ll Si = 0, si = 0;
    vector <string> ans(n);
    
    if (good[0]) {
        for (ll i = 0; i < k; i++) ans[i] = S[Si++];
    }
    else {
        ans[0] = S[0];
        for (ll i = 1; i < k; i++) ans[i] = S[Si++];
    }
    // cout << Si << endl;

    string val = "";
    for (ll i = 1; i < n-k+1; i++) {
        if (good[i]) ans[i+k-1] = S[Si++];
        else ans[i+k-1] = ans[i];
    }
    
    for (auto &x : ans) cout << x << " ";
}

int main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}
