#include <bits/stdc++.h>
using namespace std;

int n = 8, X[65], cot[65], d1[65], d2[65], cnt = 0;
char board[9][9];

void Try(int i) {
    // Duyet cac kha nang j ma X[i] nhan duoc;
    for (int j = 1; j <= n; j++) {
        if (board[i][j] != '*' && cot[j] == 1 && d1[i-j+n] == 1 && d2[i+j-1] == 1) {
            X[i] = j;
            cot[j] = d1[i-j+n] = d2[i+j-1] = 0;

            if (i == n) {
                ++cnt;
            }
            else {
                Try(i+1);
            }
            // Backtrack;
            cot[j] = d1[i-j+n] = d2[i+j-1] = 1;
        }
    }
}

int main() {
    for (int i = 1; i <= 64; i++) {
        cot[i] = d1[i] = d2[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    Try(1);
    cout << cnt;
}
