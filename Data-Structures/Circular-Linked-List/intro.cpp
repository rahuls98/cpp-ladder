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
    Node *first, *second, *last;

    last = insertNode(3, NULL);
    second = insertNode(2, last);
    first = insertNode(1, second);
    last->next = first;

    Node* itr = first;
    do{
        std::cout<<itr->data<<" ";
        itr = itr->next;
    } while(itr != first); 

    std::cout<<std::endl;

    return 0;
}