#include <iostream>
#include <queue>
#include <stack>

#define br() { std::cout<<std::endl; }

class Node {
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int data) { this->data = data; }
};

void insertNode(Node* root_ref, int data) {
    std::queue<Node*> q;
    Node* temp;
    q.push(root_ref);

    while(!q.empty()) {
        temp = q.front();

        if(temp->left) q.push(temp->left);
        else {
            temp->left = new Node(data);
            break;
        }

        if(temp->right) q.push(temp->right);
        else {
            temp->right = new Node(data);
            break;
        }

        q.pop();
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
    Node* root = new Node(1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);

    inOrder(root); br();

    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}