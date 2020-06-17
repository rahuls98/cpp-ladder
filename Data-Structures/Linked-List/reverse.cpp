#include <iostream>

class Node {
    public:
        int data;
        Node* next;
};

void insertNode(Node** head_ptr, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    Node* temp = (*head_ptr);
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void reverse(Node** head_ptr) {
    Node *prev, *curr, *next;
    prev = curr = (*head_ptr); 
    next = prev->next;

    prev->next = NULL;
    curr = next;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    (*head_ptr) = prev;
}

void print(Node** head_ptr) {
    Node* temp = (*head_ptr);
    while(temp != NULL) {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    } 
    std::cout<<std::endl;
}

void deleteList(Node** head_ptr) {
    Node* temp = (*head_ptr);
    Node* curr = temp;
    while(curr != NULL) {
        curr = temp->next;
        delete temp;
        temp = curr;
    }
}

int main() {
    Node* head = new Node();
    head->data = 10; head->next = NULL;

    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);

    print(&head); // 10 20 30 40 50
    reverse(&head);
    print(&head); // 50 40 30 20 10

    deleteList(&head);
    print(&head); // Segmentation fault: 11

    return 0;
}