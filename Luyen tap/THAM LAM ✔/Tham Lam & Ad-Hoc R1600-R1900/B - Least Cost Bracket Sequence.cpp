#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;

void solve() {
    string s; cin >> s;
    int n = (int) s.size();

    priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater<>> q;
    // Try to change the '(' at pos that will reduce the cost most
    ll cnt = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') ++cnt;
        else if (s[i] == ')') --cnt;
        else {
            ll a, b; cin >> a >> b;
            ll diff = a-b;
            q.push({diff, i});
            s[i] = ')';
            ans += b;
            --cnt;
        }

        if (cnt < 0) {
            if (q.empty()) break; // No more pos to change
            ll val = q.top().first, id = q.top().second;
            q.pop();
            s[id] = '(';
            ans += val;
            cnt += 2;
        }
    }

    if (cnt != 0) cout << "-1\n";
    else cout << ans << endl << s << endl;
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
