#include <bits/stdc++.h>
using namespace std;

long long calculate(long long n, long long index, long long sum1, long long sum2, vector <long long> nums) {
    if (index == n) {
        return abs(sum1 - sum2);
    }

    long long case1 = calculate(n, index + 1, sum1 + nums[index], sum2, nums);
    long long case2 = calculate(n, index + 1, sum1, sum2 + nums[index], nums);

    return min(case1, case2);
}

int main() {
    long long n; cin >> n;
    vector <long long> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    long long ans = calculate(n, 0, 0, 0, nums);
    cout << ans;
}
