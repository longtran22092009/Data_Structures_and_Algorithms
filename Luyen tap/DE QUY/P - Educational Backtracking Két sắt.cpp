#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Code {
    ll binaryCode, correct;
};

ll n, m, cnt = 0;
vector <Code> codes;
vector <ll> choose(5, 0);

void generateCombination(ll i, ll limit, ll curr_j) {
    for (ll j = curr_j; j < n; j++) {
        choose[i] = j;

        if (i == limit-1) {
            ll correct_code = ~codes[0].binaryCode;
            for (int idx = 0; idx < codes[0].correct; idx++) {
                ll a = 1;
                correct_code ^= (a << choose[idx]);
            }

            bool valid = true;
            for (int code_idx = 1; code_idx < m; code_idx++) {
                ll same = 0;
                auto first = bitset<35>(correct_code);
                auto second = bitset<35>(codes[code_idx].binaryCode);

                for (int pos = 0; pos < n; pos++) {
                    if (first[pos] == second[pos]) ++same;
                }

                if (same != codes[code_idx].correct) {
                    valid = false;
                }
            }

            if (valid) ++cnt;
        }
        else {
            generateCombination(i+1, limit, j+1);
        }

        choose[i] = 0;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string bin;
        ll correct;
        cin >> bin >> correct;
        codes.push_back({stoll(bin, 0, 2), correct});
    }

    generateCombination(0, codes[0].correct, 0);

    cout << cnt;
}