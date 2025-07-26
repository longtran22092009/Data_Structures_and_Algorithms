#include <bits/stdc++.h>
using namespace std;

void towerOfHaNoi(int disk, int source, int auxilary, int target) {
    if (disk == 1) {
        cout << source << " " << target << endl;
        return;
    }
    // Move disk from A to B, use C as an auxilary;
    towerOfHaNoi(disk - 1, source, target, auxilary);
    // Move disk from A to B;
    cout << source << " " << target << endl;
    // Move disk from B to C, use A as an auxilary;
    towerOfHaNoi(disk - 1, auxilary, source, target);
}

int main() {
    int n; cin >> n;
    cout << pow(2, n) - 1 << endl;
    towerOfHaNoi(n, 1, 2, 3);
}
