#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int data): data(data) {}
};

void insertNode(Node* root_ref, int data) {
    Node* temp = root_ref;
    if(data < temp->data) {
        if(temp->left) insertNode(temp->left, data);
        else {
            temp->left = new Node(data);
            return;
        }
    } else {
        if(temp->right) insertNode(temp->right, data);
        else {
            temp->right = new Node(data);
            return;
        }
    }
}

void inOrder(Node* root_ref) {
    if(root_ref) {
        inOrder(root_ref->left);
        std::cout<<root_ref->data<<" ";
        inOrder(root_ref->right);
    }
}

int main() {
    Node* root = new Node(8);
    std::vector<int> nodes = {3,10,1,6,14,4,7,13};

    for(int x: nodes) insertNode(root, x);
    inOrder(root);  // 1 3 4 6 7 8 10 13 14
    std::cout<<std::endl;

    return 0;
}