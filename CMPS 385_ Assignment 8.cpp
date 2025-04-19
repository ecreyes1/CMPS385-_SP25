// CMPS 385_ Assignment 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<iomanip>
#include<string>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) : key(val), left(nullptr), right(nullptr), parent(nullptr) {}
};
Node* findNode(int key, Node* root) {
    if (!root || root->key == key)
        return root;
    if (key < root->key)
        return findNode(key, root->left);
    else
        return findNode(key, root->right);
}


Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key);
    if (key < root->key) {
        Node* leftChild = insert(root->left, key);
        root->left = leftChild;
        leftChild->parent = root;
    }
    else {
        Node* rightChild = insert(root->right, key);
        root->right = rightChild;
        rightChild->parent = root;
    }
    return root;
}

int leftrotation(int node, Node*& root) {
    Node* x = findNode(node, root);
    if (!x || !x->right)
        return -1;

    Node* y = x->right;
    x->right = y->left;

    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;

    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;

    return 0;
}

// Right Rotation
int Rightrotation(int node, Node*& root) {
    Node* y = findNode(node, root);
    if (!y || !y->left)
        return -1;

    Node* x = y->left;
    y->left = x->right;

    if (x->right)
        x->right->parent = y;

    x->parent = y->parent;

    if (!y->parent)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;

    return 0;
}
void printTree(Node* root, int space = 0, int indent = 5) {
    if (!root) return;

    space += indent;

    printTree(root->right, space);

    cout << endl;
    for (int i = indent; i < space; i++)
        cout << " ";
    cout << root->key << "\n";

    printTree(root->left, space);
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
int main() {
    Node* root = nullptr;
    root = insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 10);
    insert(root, 25);
    insert(root, 35);
    insert(root, 50);
     
    cout << "Original Tree (sidew ays view):\n";
    printTree(root);

    cout << "\nIn-order traversal:";
    inorder(root);
    cout << " \n";

   
    cout << "\nPerforming left rotation\n";
    leftrotation(30, root);
    printTree(root);

    cout << "\ nPerforming right rotation at node\n";
    Rightrotation(40, root);
    printTree(root);

    return 0;
}
