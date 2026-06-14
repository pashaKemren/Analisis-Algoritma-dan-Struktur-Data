#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fungsi membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Root -> Right
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {

    // Membuat node sesuai gambar
    Node* root = createNode(7);

    root->left = createNode(14);
    root->right = createNode(83);

    root->left->left = createNode(91);
    root->left->right = createNode(102);

    root->left->right->left = createNode(31);
    root->left->right->right = createNode(87);

    root->left->right->left->left = createNode(93);

    root->left->right->left->left->left = createNode(24);
    root->left->right->left->left->right = createNode(76);

    root->right->left = createNode(192);
    root->right->right = createNode(932);

    root->right->right->right = createNode(153);

    root->right->right->right->left = createNode(772);
    root->right->right->right->right = createNode(812);

    cout << "Preorder : ";
    preorder(root);

    cout << "\nInorder  : ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}
