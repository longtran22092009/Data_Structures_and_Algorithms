#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    ll n, k; cin >> n >> k;
    vector <ll> arr(n);
    for (ll &x : arr) cin >> x;

    while (k--) {
        ll num; cin >> num;

        ll l = 0, r = n-1;
        bool found = false;

        while (l <= r) {
            ll mid = (l+r)/2;

            if (arr[mid] == num) {
                found = true;
                cout << "YES" << endl;
                break;
            }
            
            if (arr[mid] > num) r = mid-1;
            else l = mid+1;
        }

        if (!found) cout << "NO" << endl;

        // Use function:
        // if (binary_search(arr.begin(), arr.end(), num)) {
        //     cout << "YES" << endl;
        // }
        // else cout << "NO" << endl;
    }
}
