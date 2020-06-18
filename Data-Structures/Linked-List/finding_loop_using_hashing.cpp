#include <iostream>
#include <unordered_map>

std::unordered_map<void*, bool> visited = {};

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

Node* findLoop(Node** head_ptr) {
    
}

int main() {
    Node* last = new Node(20, NULL);
    Node* third = new Node(4, last);
    Node* second = new Node(15, third);
    Node* head = new Node(10, second);

    last->next = second;

    findLoop(&head);
}