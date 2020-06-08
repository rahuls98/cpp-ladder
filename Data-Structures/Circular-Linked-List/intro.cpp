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
    Node* temp = headPtr;
    
    while(temp->next != headPtr) temp = temp->next;

    temp->next = node;
    node->next = headPtr;
}

int main() {
    Node* head = new Node(1, NULL);
    head->next = head;
    insertNode(head, 2);
    insertNode(head, 3);

    Node* itr = head;
    do{
        printNode(itr->data);
        itr = itr->next;
    } while(itr != head); 

    std::cout<<"FIRST"<<std::endl;

    return 0;
}