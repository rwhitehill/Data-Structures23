#include <iostream>

struct Node {
    int num;
    Node* left{};
    Node* right{};
    Node() = delete;
    Node(int n) : num{ n } {};
};

typedef Node* NodePtr;

void preorder(const NodePtr root) {
    if (root) {
        std::cout << root->num << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(const NodePtr root) {
    if (root) {
        inorder(root->left);
        std::cout << root->num << " ";
        inorder(root->right);
    }
}

void postorder(const NodePtr root) {
    if (root) {
        inorder(root->left);
        inorder(root->right);
        std::cout << root->num << " ";
    }
}

int main()
{
    
    NodePtr root = new Node { 1 };
    root->left = new Node { 7 };
    root->right = new Node { 9 };

    root->left->left = new Node { 2 };
    root->left->right = new Node { 6 };
    root->right->right = new Node { 92 };


    root->left->right->left = new Node { 5 };
    root->left->right->right = new Node { 11 };
    root->right->right->left = new Node { 52 };
   
    preorder(root);
    std::cout << std::endl;
    inorder(root);
    std::cout << std::endl;
    postorder(root);
    std::cout << std::endl;
}
