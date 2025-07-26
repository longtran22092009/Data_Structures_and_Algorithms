#include <bits/stdc++.h>
using namespace std;

set <int> readings;

void solve(int day, int milk_1, vector <int> barn_1, int milk_2, vector <int> barn_2) {
    if (day == 4) {
        readings.insert(milk_1);
        return;
    }

    // Duyet cac kha nang j cho X[i];
    for (int i = 0; i < barn_1.size(); i++) {
        int choose_bucket = barn_1[i];

        vector <int> new_barn_1 = barn_1;
        new_barn_1.erase(begin(new_barn_1) + i);
        vector <int> new_barn_2 = barn_2;
        new_barn_2.push_back(choose_bucket);

        solve(day + 1, milk_2 + choose_bucket, new_barn_2, milk_1 - choose_bucket, new_barn_1);
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    // Parse the input;
    vector <int> barn_1(10), barn_2(10);
    for (int i = 0; i < 10; i++) {
        cin >> barn_1[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> barn_2[i];
    }
    solve(0, 1000, barn_1, 1000, barn_2);
    cout << readings.size();
}
