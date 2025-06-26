#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 105, INF = (int) 1e9+5;
int n, cnt = 0, a[mxN];
bool prime[mxN], used[mxN];

void sieve() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = 0;

    for (int i = 2; i <= 100; i++) {
        if (!prime[i]) continue;
        for (int j = i*i; j <= 100; j += i) prime[j] = 0;
    }
}

void backtrack(int i, int op) {
    // Need to count all valid permutation
    // Just not need to print all of them
    if (op == 1 && cnt >= 10000) return; 
    if (i == 2*n+1) {
        if (!prime[a[2*n] + a[1]]) return; // Check the final pair
        ++cnt;

        if (op == 1 && cnt <= 10000) {
            for (int i = 1; i <= 2*n; i++) cout << a[i] << " ";
            cout << endl;
        }
        return;
    }

    for (int x = 2; x <= 2*n; x++) {
        if (used[x] || !prime[a[i-1] + x]) continue;
        used[x] = 1;
        a[i] = x;
        backtrack(i+1, op);
        used[x] = 0;
    }
}

void solve() {
    cin >> n;
    sieve();
    // Find how many valid permutation are there
    a[1] = 1;
    backtrack(2, 0);
    cout << cnt << endl;
    // Print the answer
    cnt = 0;
    backtrack(2, 1);
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
