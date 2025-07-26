#include <bits/stdc++.h>
using namespace std;

int ans;
int cards[4];
vector <int> card_permutation;
bool chosen[4];

// Funtion to calculate with operations;
int calculate(int option, int a, int b) {
    switch (option) {
        case 0:
            return a + b;
        case 1:
            return a - b;
        case 2:
            return a * b;
        case 3:
            if (b == 0 || a % b != 0) return INT32_MIN;
            return a / b;
    }
    return INT32_MIN;
}

// Calculate to find the expression that give max result;
void generate() {
    // Have enough card for a hand;
    if (card_permutation.size() == 4) {
        // Case 1: Normal calculation (L -> R);
        for (int option1 = 0; option1 <= 3; option1++) {
            for (int option2 = 0; option2 <= 3; option2++) {
                for (int option3 = 0; option3 <= 3; option3++) {
                    int part_1 = calculate(option1, card_permutation[0], card_permutation[1]);
                    // Check if it is valid to calculate;
                    if (part_1 == INT32_MIN) continue;

                    int part_2 = calculate(option2, part_1, card_permutation[2]);
                    // Check if it is valid to calculate;
                    if (part_2 == INT32_MIN) continue;

                    int part_3 = calculate(option3, part_2, card_permutation[3]);
                    // Check if it is valid to calculate;
                    if (part_3 == INT32_MIN) continue;

                    // Return the result of operations;
                    if (part_3 <= 24) ans = max(ans, part_3);
                }
            }
        }

        // Case 2: Two side first ((a, b) ... (c, d));
        for (int option1 = 0; option1 <= 3; option1++) {
            for (int option2 = 0; option2 <= 3; option2++) {
                for (int option3 = 0; option3 <= 3; option3++) {
                    int part_1 = calculate(option1, card_permutation[0], card_permutation[1]);
                    // Check if it is valid to calculate;
                    if (part_1 == INT32_MIN) continue;

                    int part_2 = calculate(option2, card_permutation[2], card_permutation[3]);
                    // Check if it is valid to calculate;
                    if (part_2 == INT32_MIN) continue;

                    int part_3 = calculate(option3, part_1, part_2);
                    // Check if it is valid to calculate;
                    if (part_3 == INT32_MIN) continue;

                    // Return the result of operations;
                    if (part_3 <= 24) ans = max(ans, part_3);
                }
            }
        }
    }  
    else {
        // Do not have enough cards in hand;
        for (int i = 0; i <= 3; i++) {
            // Check if already use this card;
            if (chosen[i]) continue;
            chosen[i] = true;
            card_permutation.push_back(cards[i]);
            generate();

            // Backtrack;
            chosen[i] = false;
            card_permutation.pop_back();
        }
    }
}

int main() {
    // Parse the input;
    int N; cin >> N;
    while (N--) {
        ans = INT32_MIN;
        for (int i = 0; i <= 3; i++) cin >> cards[i];
        generate();
        cout << ans << endl;
    }
}
