#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
#define IN "A.in"
#define OUT "A.out"
 
 
const ll MOD = (ll) 1e9 + 7;
 
void solve() {
    ll n, limit; cin >> n >> limit;
 
    vector <pair <int, int>> items(n+1);
    for (ll i = 1; i <= n; i++) cin >> items[i].first;
    for (ll i = 1; i <= n; i++) cin >> items[i].second;
 
    // dp[i][page]
    vector <vector <int>> dp(n+1, vector <int>(limit+1, 0));
 
    for (ll i = 1; i <= n; i++) {
        for (ll price = 1; price <= limit; price++) {
            dp[i][price] = dp[i-1][price];
 
            if (price - items[i].first >= 0) {
                dp[i][price] = max(dp[i][price], dp[i-1][price - items[i].first] + items[i].second);
            }
        }
    }
 
    cout << dp[n][limit] << endl;
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

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define endl '\n'
 
// #define IN "A.in"
// #define OUT "A.out"
 

// const ll MOD = (ll) 1e9 + 7;
 
// void solve() {
//     ll n, limit; cin >> n >> limit;
 
//     vector <pair <ll, ll>> items(n+1);
//     for (ll i = 1; i <= n; i++) cin >> items[i].first;
//     for (ll i = 1; i <= n; i++) cin >> items[i].second;
 
//     vector <ll> dp(limit+1, 0);

//     for (ll i = 1; i <= n; i++) {
//         for (ll j = limit; j >= items[i].first; j--) {
//             dp[j] = max(dp[j], dp[j - items[i].first] + items[i].second);
//         }
//     }

//     cout << dp[limit] << endl;
// }
 
// int main() {
//     if (fopen(IN, "r")) {
//         freopen(IN, "r", stdin);
//         freopen(OUT, "w", stdout);
//     }
 
//     ios_base::sync_with_stdio(0); cin.tie(0);
    
//     // ll t; cin >> t;
//     // while (t--)
//     solve();
// }