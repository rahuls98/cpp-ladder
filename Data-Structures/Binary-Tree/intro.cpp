#include <iostream>
#define br() std::cout<<std::endl;

class Node {
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int data) {
        this->data = data;
    }
};

void preOrder(Node* ptr) {
    if(ptr) {
        std::cout<<ptr->data<<" ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    preOrder(root); br();

    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
}