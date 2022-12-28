#include <iostream>

using namespace std;


struct Node {
    int value;
    Node *left, *right;
};

void Insert(Node*& root, int value) {

    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }

    if (value > root->value) {
        Insert(root->right, value);
    } else {
        Insert(root->left, value);
    }
} 


// Правий обхід *order(root->left) і *order(root->right) 

void preorder(Node* root) {
    if (root) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}


int product(Node* root) {
    int prod = 1;
    if (root) {
        prod *= root->value;
        prod *= product(root->left);
        prod *= product(root->right);
    }

    return prod;
}

int main() {

    Node *root = nullptr;

    Insert(root, 4);
    Insert(root, 1);
    Insert(root, 2);
    Insert(root, 7);
    Insert(root, 3);
    Insert(root, 5);
    Insert(root, 6);

    cout << "preorder: ";
    preorder(root);
    cout << endl;

    cout << "inorder: ";
    inorder(root);
    cout << endl;

    cout << "postorder: ";
    postorder(root);
    cout << endl;

    cout << "Product: " << product(root);

    return 0;
}
