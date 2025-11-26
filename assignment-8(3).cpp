#include <iostream>
#include <algorithm>
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

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (!node) return nullptr;
        if (val < node->data) node->left = deleteNode(node->left, val);
        else if (val > node->data) node->right = deleteNode(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    int maxDepth(Node* node) {
        if (!node) return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    int minDepth(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        if (!node->left) return 1 + minDepth(node->right);
        if (!node->right) return 1 + minDepth(node->left);
        return 1 + min(minDepth(node->left), minDepth(node->right));
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

    cout << "Max Depth: " << tree.maxDepth(tree.root) << endl;
    cout << "Min Depth: " << tree.minDepth(tree.root) << endl;

    tree.root = tree.deleteNode(tree.root, 20);
    cout << "Deleted 20. New Max Depth: " << tree.maxDepth(tree.root) << endl;

    return 0;
}