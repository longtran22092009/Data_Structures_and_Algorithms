#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "bcs.in"
#define OUT "bcs.out"

struct Piece {
    char shape[8][8];
    int start_col = 7, start_row = 7, end_col = 0, end_row, num = 0;
};

const int mxN = 105, INF = (int) 1e9+5;

void solve() {
    int n, k; cin >> n >> k;
    char original[n][n];
    int original_num = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> original[i][j];
            if (original[i][j] == '#') 
                    ++original_num;
        }
    }

    vector <Piece> pieces(k);
    for (auto &p : pieces) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> p.shape[i][j];
                if (p.shape[i][j] == '#') {
                    ++p.num;
                    p.start_col = min(p.start_col, j);
                    p.end_col = max(p.end_col, j);
                    p.start_row = min(p.start_row, i);
                    p.end_row = max(p.end_row, i);
                }
            }
        }
    }

    for (int idx1 = 0; idx1 < k; idx1++) {
        for (int idx2 = idx1 + 1; idx2 < k; idx2++) {
            Piece p1 = pieces[idx1];
            Piece p2 = pieces[idx2];
            // If the total part of two piece are different from the original so we pass it;
            if (p1.num + p2.num != original_num) continue;
            // Loop through all row anf col that could validly put a piece in;
            for (int row1 = 0; row1 < n - (p1.end_row - p1.start_row); row1++) {
                for (int col1 = 0; col1 < n - (p1.end_col - p1.start_col); col1++) {
                    char connecting[n][n];
                    memset(connecting, '.', sizeof(connecting));

                    // Loop through all row and col, each time try to put the piece in and see if it is valid;
                    int i = p1.start_row, j = p1.start_col;
                    for (int curr_row = row1; curr_row <= row1 + (p1.end_row - p1.start_row); curr_row++) {
                        for (int curr_col = col1; curr_col <= col1 + (p1.end_col - p1.start_col); curr_col++) {

                            connecting[curr_row][curr_col] = p1.shape[i][j];
                            ++j;
                        }
                        j = p1.start_col;
                        ++i;
                    }
                    char pre_connecting[n][n];
                    copy(&connecting[0][0], &connecting[0][0]+n*n, &pre_connecting[0][0]);
                            
                    for (int row2 = 0; row2 < n - (p2.end_row - p2.start_row); row2++) {
                        for (int col2 = 0; col2 < n - (p2.end_col - p2.start_col); col2++) {
                            copy(&pre_connecting[0][0], &pre_connecting[0][0]+n*n, &connecting[0][0]);

                            int i = p2.start_row, j = p2.start_col;
                            for (int curr_row = row2; curr_row <= row2 + (p2.end_row - p2.start_row); curr_row++) {
                                for (int curr_col = col2; curr_col <= col2 + (p2.end_col - p2.start_col); curr_col++) {

                                    if (connecting[curr_row][curr_col] != '#') {
                                        connecting[curr_row][curr_col] = p2.shape[i][j];
                                    }
                                    ++j;
                                }
                                j = p2.start_col;
                                ++i;
                            }

                            bool correct = true;
                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < n; j++) {
                                    if (connecting[i][j] != original[i][j]) correct = false;
                                }
                            }

                            if (correct) {
                                cout << idx1 + 1 << " " << idx2 + 1;
                                return;
                            }
                        }
                    } 
                }
            }
        }
    }
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // ll t; cin >> t;
    // while (t--)
    solve();
}
