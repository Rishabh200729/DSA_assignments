#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* searchRecursive(Node* node, int val) {
        if (!node || node->data == val) return node;
        if (val < node->data) return searchRecursive(node->left, val);
        return searchRecursive(node->right, val);
    }

    Node* searchIterative(Node* node, int val) {
        while (node) {
            if (val == node->data) return node;
            if (val < node->data) node = node->left;
            else node = node->right;
        }
        return nullptr;
    }

    Node* findMax(Node* node) {
        if (!node) return nullptr;
        while (node->right) node = node->right;
        return node;
    }

    Node* findMin(Node* node) {
        if (!node) return nullptr;
        while (node->left) node = node->left;
        return node;
    }

    Node* getSuccessor(Node* root, int val) {
        Node* curr = searchIterative(root, val);
        if (!curr) return nullptr;
        if (curr->right) return findMin(curr->right);

        Node* succ = nullptr;
        Node* ancestor = root;
        while (ancestor != curr) {
            if (curr->data < ancestor->data) {
                succ = ancestor;
                ancestor = ancestor->left;
            } else ancestor = ancestor->right;
        }
        return succ;
    }

    Node* getPredecessor(Node* root, int val) {
        Node* curr = searchIterative(root, val);
        if (!curr) return nullptr;
        if (curr->left) return findMax(curr->left);

        Node* pred = nullptr;
        Node* ancestor = root;
        while (ancestor != curr) {
            if (curr->data > ancestor->data) {
                pred = ancestor;
                ancestor = ancestor->right;
            } else ancestor = ancestor->left;
        }
        return pred;
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    int val = 40;
    if (tree.searchRecursive(tree.root, val)) cout << "Recursive Found " << val << endl;
    if (tree.searchIterative(tree.root, val)) cout << "Iterative Found " << val << endl;

    cout << "Max: " << tree.findMax(tree.root)->data << endl;
    cout << "Min: " << tree.findMin(tree.root)->data << endl;

    Node* succ = tree.getSuccessor(tree.root, 40);
    cout << "Successor of 40: " << (succ ? to_string(succ->data) : "None") << endl;

    Node* pred = tree.getPredecessor(tree.root, 60);
    cout << "Predecessor of 60: " << (pred ? to_string(pred->data) : "None") << endl;

    return 0;
}