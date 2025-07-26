#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, M, cost, stalls[101];
bool isUsed = false;

// O(10^2);
bool isOk() {
    for (int i = 1; i <= 100; i++) {
        if (stalls[i] > 0) return false;
    }
    return true;
}

ll solve(int idx, ll cost, vector <tuple <int, int, int, int>> conditioners, bool isUsed) {
    // Try to reduce temperature of some stalls by ci;
    if (isUsed) {
        for (int j = get<0>(conditioners[idx]); j <= get<1>(conditioners[idx]); j++) {
            stalls[j] -= get<2>(conditioners[idx]);
        }
    }
    // Check for return the cost;
    if (idx == M-1) {
        if (isOk()) return cost;
        return LONG_MAX;
    }

    // Used cases;
    ll case1 = solve(idx+1, cost + get<3>(conditioners[idx+1]), conditioners, isUsed = true);
    // Backtrack;
    for (int j = get<0>(conditioners[idx+1]); j <= get<1>(conditioners[idx+1]); j++) {
        stalls[j] += get<2>(conditioners[idx+1]);
    }
    // Unused cases;
    ll case2 = solve(idx+1, cost, conditioners, isUsed = false);

    return min(case1, case2);
}

int main() {
    // Parse the input;
    cin >> N >> M;
    vector <tuple <int, int, int, int>> conditioners(M);
    for (int i = 0; i < N; i++) {
        int startStall, endStall, temperature;
        cin >> startStall >> endStall >> temperature;

        for (int i = startStall; i <= endStall; i++)
            stalls[i] += temperature;
    }
    for (int i = 0; i < M; i++) {
        int startCool, endCool, temperature, cost;
        cin >> startCool >> endCool >> temperature >> cost;
        conditioners[i] = {startCool, endCool, temperature, cost};
    }

    // Find the minimum cost to satisfy all the cow;
    ll minCost = solve(-1, 0, conditioners, isUsed);
    cout << minCost;
}
