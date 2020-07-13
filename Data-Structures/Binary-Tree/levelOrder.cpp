#include <iostream>
#include <queue>

#define br() std::cout<<std::endl;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) { 
        this->data = data;
        this->left = NULL;
        this->right = NULL; 
    }
};

void levelOrder(Node* root_ref) {
    if(root_ref == NULL) return;
    
    std::queue<Node *> q;
    q.push(root_ref);

    while(q.empty() == false) {
        Node* temp = q.front();
        std::cout<<temp->data<<" ";
        q.pop();

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);        
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    levelOrder(root); br();     // 1 2 3 4 5

    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
}