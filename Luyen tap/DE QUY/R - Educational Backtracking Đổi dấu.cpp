#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, ans = LONG_LONG_MAX;

ll calculate(vector <ll> nums, vector <ll> finePerNum, vector <ll> fineTwoNum) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (res >= 0) {
            if (LONG_LONG_MAX - res < finePerNum[i] * nums[i]) return LONG_LONG_MAX;
        }
        else {
            if (LONG_LONG_MAX - abs(res) < finePerNum[i] * nums[i]) return LONG_LONG_MAX;
        }

        res += finePerNum[i] * nums[i];
    }

    ll idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (res >= 0) {
                if (LONG_LONG_MAX - res < finePerNum[i] * nums[i]) return LONG_LONG_MAX;
            }
            else {
                if (LONG_LONG_MAX - abs(res) < finePerNum[i] * nums[i]) return LONG_LONG_MAX;
            }

            res += fineTwoNum[idx] * nums[i] * nums[j];
            ++idx;
        }
    }

    return res;
}

void generateSubset(ll i, vector <ll> nums, vector <ll> finePerNum, vector <ll> fineTwoNum) {
    if (i == n) {
        ll res = calculate(nums, finePerNum, fineTwoNum);

        ans = min(ans, res);

        return;
    }
    
    nums[i] = -1;
    generateSubset(i+1, nums, finePerNum, fineTwoNum);
    nums[i] = 1;

    generateSubset(i+1, nums, finePerNum, fineTwoNum);
}

int main() {
    cin >> n;
    vector <ll> finePerNum(n);
    vector <ll> fineTwoNum;
    for (auto &x : finePerNum) cin >> x;

    for (int time = n-1; time >= 1; time--) {
        for (int i = 0; i < time; i++) {
            ll x; cin >> x;
            fineTwoNum.push_back(x);
        }
    }

    vector <ll> nums(n, 1);
    generateSubset(0, nums, finePerNum, fineTwoNum);

    cout << ans;
}
