#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() : root(nullptr) {}

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    bool isBST(Node* node, long long minVal, long long maxVal) {
        if (!node) return true;
        if (node->data <= minVal || node->data >= maxVal) return false;
        return isBST(node->left, minVal, node->data) && isBST(node->right, node->data, maxVal);
    }
};

int main() {
    BinaryTree tree;
    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 20);

    cout << "Tree 1 is BST: " << (tree.isBST(tree.root, LONG_LONG_MIN, LONG_LONG_MAX) ? "True" : "False") << endl;

    tree.root->left->data = 15; 

    cout << "Tree 2 is BST: " << (tree.isBST(tree.root, LONG_LONG_MIN, LONG_LONG_MAX) ? "True" : "False") << endl;

    return 0;
}