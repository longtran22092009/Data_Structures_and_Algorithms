#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t, n;

void findDepth(ll curr_depth, vector <ll> curr_tree, vector <ll> &depth) {
    if (curr_tree.empty()) return;
    
    auto pos = max_element(curr_tree.begin(), curr_tree.end());
    depth[*pos] = curr_depth;

    vector <ll> left_tree(curr_tree.begin(), pos);
    vector <ll> right_tree(pos+1, curr_tree.end());

    findDepth(curr_depth+1, left_tree, depth);
    findDepth(curr_depth+1, right_tree, depth);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector <ll> tree(n);
        for (auto &x : tree) cin >> x;

        vector <ll> depth(n+1, 0);
        findDepth(0, tree, depth);

        for (auto x : tree) cout << depth[x] << " ";
        cout << endl;
    }
}
