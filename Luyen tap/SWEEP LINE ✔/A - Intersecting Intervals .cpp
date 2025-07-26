#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005;
const ll INF = (ll) 1e18;
int n;
vector <pair <int, int>> a; // {pos, 0/1} => 0: start of a interval, 1; end of a interval

void solve() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        a.push_back({l, 0});
        a.push_back({r, 1});
    }
    sort(a.begin(), a.end());

    ll ans = 0, cnt = 0;
    for (int i = 0; i < n*2; i++) {
        // cout << "Position: " << a[i].first << "-> " << a[i].second << endl;
        if (a[i].second == 0) {
            if (cnt+1 >= 2) ans += cnt;
            ++cnt;
        }
        else --cnt;
    }

    cout << ans << endl;
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