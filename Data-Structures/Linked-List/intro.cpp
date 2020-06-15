#include <iostream>

#define printNode(x) { std::cout<<"[ "<<x<<" ]"<<" --> "; }

class Node {
    public:
        int data;
        Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

void insertNode(Node* headPtr, int data) {
    Node* node = new Node(data, NULL);
    
    while(headPtr->next != NULL) headPtr = headPtr->next;

    headPtr->next = node;
    node->next = NULL;
}

int main() {
    Node* head = new Node(1, NULL);
    insertNode(head, 2);
    insertNode(head, 3);

    Node* itr = head;
    while(itr!=NULL){
        printNode(itr->data);
        itr = itr->next;
    } 
    std::cout<<"NULL"<<std::endl;

    return 0;
}