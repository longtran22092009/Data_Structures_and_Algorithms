#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, cnt = 0;
vector <int> words;

void generateSubset(int i, int curr_ans) {
    if (i == n) {
        if (curr_ans == pow(2, 26) - 1) ++cnt;
        return;
    }

    int new_ans = curr_ans;
    new_ans = new_ans | words[i];

    generateSubset(i+1, new_ans);
    generateSubset(i+1, curr_ans);
}
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int bin = 0;
        for (int c : s) {
            int index = c - 'a';
            bin = bin | (1 << (26 - (index+1)));
        }

        words.push_back(bin);
    }

    generateSubset(0, 0);
    cout << cnt;
}
