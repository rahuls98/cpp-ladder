#include <iostream>

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int data, Node* next, Node* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

void insertNode(Node* ptr, int data) {
    Node* node = new Node(data, NULL, NULL);
    
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = node;
    node->prev = ptr;
    node->next = NULL;
}

int main() {
    Node *head = new Node(1, NULL, NULL);

    insertNode(head, 2);
    insertNode(head, 3);

    Node* ptr = head;
    while(ptr != NULL) {
        if(ptr->prev == NULL) std::cout<<"PREV: NULL"<<" --- ";
        else std::cout<<"PREV: "<<ptr->prev->data<<" --- ";

        std::cout<<ptr->data<<" --- ";

        if(ptr->next == NULL) std::cout<<"NEXT: NULL";
        else std::cout<<"NEXT: "<<ptr->next->data<<" ";

        std::cout<<std::endl;

        ptr = ptr->next;
    }

    return 0;
}