#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, cnt = 0, shortest_dis = LONG_LONG_MAX, distances[51][51];
vector <ll> X(51), ans(51);
vector <bool> visited(51, 0);

void findCycle(ll i, ll curr_node, ll curr_dis) {
    cnt++;
    for (ll j = 2; j <= n; j++) {
        if (curr_dis > shortest_dis || cnt == 1000000) return;

        if (!visited[j]) {
            visited[j] = 1;
            X[i] = j;

            curr_dis += distances[curr_node][j];

            if (i == k - 2) {
                if (curr_dis + distances[j][1] < shortest_dis) {
                    shortest_dis = curr_dis + distances[j][1];
                    ans = X;
                }
            }
            else {
                findCycle(i+1, j, curr_dis);
            }

            // Backtracking;
            visited[j] = 0;
            X[i] = 0;
            curr_dis -= distances[curr_node][j];
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> distances[i][j];
        }
    }
    
    findCycle(0, 1, 0);

    cout << shortest_dis << endl << 1 << " ";
    for (int i = 0; i < k-1; i++) {
        cout << ans[i] << " ";
    }
}
