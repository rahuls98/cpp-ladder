#include <iostream>
#include <stack>

class Node {
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int data) { this->data = data; }
};

void zigZagOrder(Node* root_ref, bool direction) {
    if(!root_ref) return;

    std::cout<<std::endl;
    Node* temp;
    std::stack<Node*> s1;
    std::stack<Node*> s2;

    if(direction) s1.push(root_ref);
    else s2.push(root_ref);

    while(!s1.empty() || !s2.empty()) {
        if(direction) {
            while(!s1.empty()) {
                temp = s1.top();
                std::cout<<temp->data<<" ";
                if(temp->left) s2.push(temp->left);
                if(temp->right) s2.push(temp->right);
                s1.pop();
            }
        } else {
            while(!s2.empty()) {
                temp = s2.top();
                std::cout<<temp->data<<" ";
                if(temp->right) s1.push(temp->right);
                if(temp->left) s1.push(temp->left);
                s2.pop();
            }
        }
        direction = !direction;
    }
    std::cout<<std::endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int choice;
    std::cout<<"First level direction: "<<std::endl;
    std::cout<<"1) L->R\n2) R->L\n";
    std::cout<<"Enter choice (1 or 2): ";
    std::cin>>choice;

    switch(choice) {
        case 1: zigZagOrder(root, true); break;     // 1 3 2 4 5 6 7
        case 2: zigZagOrder(root, false); break;    // 1 2 3 7 6 5 4
        default: std::cout<<"Invalid choice!"; break;
    }

    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
}