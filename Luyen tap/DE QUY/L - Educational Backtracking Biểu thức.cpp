#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t, n, m, cnt = 0;

ll operation(int op, ll a, ll b) {
    if (op == 1) return a + b;
    if (op == 2) return a - b;
    return a * b;
}

vector <ll> choose;
void calculate(int i, vector <ll> nums) {
    for (int option = 1; option <= 3; option++) {
        vector <ll> new_nums = nums;

        if (option == 3) {
            if (i != 0) choose.push_back(choose[i-1]);
            else choose.push_back(1);

            new_nums[i+1] = operation(option, nums[i], nums[i+1]) % m;
            new_nums[i] = 0;
        }
        else choose.push_back(option);

        if (i == n - 2) {
            ll res = new_nums[0];
            for (int idx = 0; idx < n-1; idx++) {
                res = operation(choose[idx], res, new_nums[idx+1]);
            }

            if (res % m == 0) {
                ++cnt;
            }
        }
        else {
            calculate(i+1, new_nums);
        }

        choose.pop_back();
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        
        vector <ll> numbers(n);
        for (auto &x : numbers) cin >> x;

        if (m == 0) {
            cout << 0 << endl;
            continue;
        }

        cnt = 0;
        calculate(0, numbers);

        cout << cnt << endl;
    }
}
