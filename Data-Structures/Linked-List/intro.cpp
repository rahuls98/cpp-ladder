#include <iostream>

class Node {
    public:
        int data;
        Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

Node* insertNode(int data, Node* next) {
    Node* node = new Node(data, next);
    return node;
}

int main() {
    Node* third = insertNode(3, NULL);
    Node* second = insertNode(2, third);
    Node* head = insertNode(1, second);

    Node* itr = head;
    while(itr!=NULL){
        std::cout<<itr->data<<" ";
        itr = itr->next;
    } 
    std::cout<<std::endl;
    return 0;
}