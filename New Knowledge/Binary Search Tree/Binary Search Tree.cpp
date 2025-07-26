#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18, MOD = (ll) 1e9+7;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = right = nullptr;
    }
};

struct BST {
    Node* root = nullptr;

    Node* insert(Node* node, int val) {
        if (node == nullptr) return new Node(val);

        if (val > node->val) node->right = insert(node->right, val);
        else node->left = insert(node->left, val);

        return node;
    }

    Node* search(Node* curr, int val) {
        if (curr == nullptr || curr->val == val) return curr;
        
        if (val > curr->val) return search(curr->right, val);
        return search(curr->left, val);
    }
    
    Node* remove(Node* curr, int val) {
        if (root == nullptr) return root;
        
        if (val > curr->val) remove(curr->right, val);
        else if (val < curr->val) remove(curr->left, val);
        else {
            // 0 children or only right child
            if (curr->left == nullptr) {
                // Replace the curr node with the rigth node
                Node* tmp = curr->right;
                delete curr;
                return tmp;
            }
            // 0 children or only left child
            if (curr->right == nullptr) {
                Node* tmp = curr->left;
                delete curr;
                return tmp;
            }
            // 2 children
            Node* minRight = getSuccessor(curr); // Min value in the right branch from curr node
            curr->val = minRight->val; // Swap the value of the curr node and the minRight node
            curr->right = remove(curr->right, minRight->val); // Remove the curr node (swapped)
        }
        
        return curr;
    }
    
    Node* getSuccessor(Node* curr) {
        curr = curr->right;
        while (curr != nullptr && curr->left != nullptr)
            curr = curr->left;
        return curr;
    }

    void inOrder(Node* curr) {
        if (curr != nullptr) {
            // Left -> node -> right
            inOrder(curr->left);
            cout << curr->val << " ";
            inOrder(curr->right);
        }
    }
};

void solve() {
    BST bst;

    bst.root = new Node(10);
    bst.root->left = new Node(5);
    bst.root->right = new Node(15);
    bst.root->right->left = new Node(12);
    bst.root->right->right = new Node(18);
    int x = 15;

    bst.root = bst.remove(bst.root, x);
    bst.inOrder(bst.root);
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}
