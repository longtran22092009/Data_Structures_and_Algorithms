#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, limit;
bool possible = false;
vector <ll> type(9, 0);
char board[8][8];

bool check(char board[8][8]) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (board[row][col] == '.') return false;
        }
    }

    return true;
}

void placeL(ll idx) {
    if (idx == limit) {
        if (check(board)) possible = true;

        return;
    }
    
    for (ll curr_row = 0; curr_row < n-1; curr_row++) {
        for (ll curr_col = 0; curr_col < m-1; curr_col++) {
            // Check enough space;
            if (type[idx] == 1) {
                if (board[curr_row][curr_col] == '#' || board[curr_row+1][curr_col] == '#' || board[curr_row+1][curr_col+1] == '#')
                    continue;
                
                board[curr_row][curr_col] = '#';
                board[curr_row+1][curr_col] = '#';
                board[curr_row+1][curr_col+1] = '#';
                
                if (check(board)) possible = true;

                placeL(idx+1);

                board[curr_row][curr_col] = '.';
                board[curr_row+1][curr_col] = '.';
                board[curr_row+1][curr_col+1] = '.';
            }
            else {
                if (board[curr_row][curr_col+1] == '#' || board[curr_row+1][curr_col] == '#' || board[curr_row+1][curr_col+1] == '#')
                    continue;

                board[curr_row][curr_col+1] = '#';
                board[curr_row+1][curr_col] = '#';
                board[curr_row+1][curr_col+1] = '#';
                
                if (check(board)) possible = true;

                placeL(idx+1);

                board[curr_row][curr_col+1] = '.';
                board[curr_row+1][curr_col] = '.';
                board[curr_row+1][curr_col+1] = '.';
            }
        }
    }
}

void generateSubset(ll i) {
    for (ll j = 1; j <= 2; j++) {
        type[i] = j;

        if (i == limit - 1) {
            placeL(0);
        }
        else {
            generateSubset(i+1);
        }

        type[i] = 0;
    }
}

int main() {
    cin >> n >> m;
    limit = (n * m) / 4;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    if (check(board)) possible = true;
    generateSubset(0);
    
    if (possible) cout << "YES";
    else cout << "NO";
}
