#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Require {
    ll first, second, gcd;
};

ll n, m, x, cnt = 0;
vector <Require> require;
vector <set <ll>> numsPerGcd(13);
vector <set <ll>> possibleValuePerPos(10);
vector <ll> choose(9, 0);
set <ll> check_num;

// O(x^2 + m*max(numsPerGcd[i].size()) + x);
void findNumsPerGcd() {
    for (int a = 1; a <= x; a++) {
        for (int b = a; b <= x; b++) {
            ll pos = __gcd(a, b);
            numsPerGcd[pos].insert(a);
            numsPerGcd[pos].insert(b);
        }
    }

    for (auto it : require) {
        for (auto num : numsPerGcd[it.gcd]) {
            possibleValuePerPos[it.first].insert(num);
            possibleValuePerPos[it.second].insert(num);
        }

        check_num.insert(it.first);
        check_num.insert(it.second);
    }

    for (int i = 0; i < n; i++) {
        if (possibleValuePerPos[i].empty()) possibleValuePerPos[i].insert(0);
    }
}

void generateCombination(ll i) {
    for (auto j : possibleValuePerPos[i]) {
        choose[i] = j;
        
        if (i == n-1) {
            bool valid = true;
            for (auto it : require) {
                if (__gcd(choose[it.first], choose[it.second]) != it.gcd) valid = false;
            }

            if (valid) ++cnt;
        }
        else {
            generateCombination(i+1);
        }
        
        choose[i] = 0;
    }
}

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        ll a, b, g; cin >> a >> b >> g;
        require.push_back({a-1, b-1, g});
    }

    findNumsPerGcd();
    generateCombination(0);

    ll freeNum = n - check_num.size();
    freeNum = pow(x, freeNum);
    
    cout << cnt * freeNum;
}
