
#include <iostream>
#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
Node* insert(int x, Node* root) {
    if (root == nullptr) {
        return new Node(x);
    }
    if (x < root->data) {
        root->left = insert(x, root->left);
    }
    else if (x > root->data) {
        root->right = insert(x, root->right);
    }
    return root;
}
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}
Node* deleteBST(int x, Node* root) {
    if (root == nullptr)
        return nullptr;

    if (x < root->data) {
        root->left = deleteBST(x, root->left);
    }
    else if (x > root->data) {
        root->right = deleteBST(x, root->right);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteBST(temp->data, root->right);
    }
    return root;
}

void printTree(Node* root) {
    if (root == nullptr) return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(20, root);
    insert(11, root);
    insert(27, root);
    insert(18, root);
    insert(5, root);
    insert(85, root);
    insert(39, root);

    cout << "Inorder traversal: ";
    printTree(root);
    cout << endl;

    root = deleteBST(50, root);

    cout << "After deleting 50: ";
    printTree(root);
    cout << endl;

    return 0;
}

