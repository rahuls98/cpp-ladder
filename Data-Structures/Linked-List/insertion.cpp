#include <iostream>

class Node {
    public:
        int data;
        Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void after(Node** head_ref, int after, int new_data) {
    Node* new_node = new Node();
    Node* temp = (*head_ref);
    while(temp != NULL) {
        if(temp->data == after) {
            new_node->data = new_data;
            new_node->next = temp->next;
            temp->next = new_node;
            break;
        }
        temp = temp->next;
    }
}

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* temp = (*head_ref);
    while(temp->next != NULL) temp = temp->next;

    new_node->data = new_data;
    new_node->next = NULL;
    temp->next = new_node;
}

void print(Node** head_ref) {
    Node* temp = (*head_ref);
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
    head->data = 10;
    head->next = NULL;

    print(&head);                       // 10
    push(&head, 20); print(&head);      // 20 10
    append(&head, 30); print(&head);    // 20 10 30
    after(&head, 10, 40); print(&head); // 20 10 40 30

    deleteList(&head);
    print(&head); // Segmentation fault: 11
    
    return 0;
}