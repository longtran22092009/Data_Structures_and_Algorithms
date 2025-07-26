#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
vector <pair <string, string>> constraints;
vector <string> name = {"Beatrice", "Belinda", "Bella", "Bessie",  "Betsy", "Blue", "Buttercup", "Sue"};

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    // Parse the input;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string a, tmp, b;
        cin >> a >> tmp >> tmp >> tmp >> tmp >> b;
        constraints.push_back({a, b});
    }
    sort(name.begin(), name.end());

    while (next_permutation(name.begin(), name.end())) {
        bool ok = true;
        for (auto it : constraints) {
            auto pos1 = find(name.begin(), name.end(), it.first);
            auto pos2 = find(name.begin(), name.end(), it.second);

            if (abs(pos1 - pos2) != 1) ok = false;
        }
        if (ok) break;
    }

    for (auto cow : name) cout << cow << endl;
}
