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

void nodeInsert(Node** tail_ptr, int new_data) {
    Node* new_node = new Node(new_data, NULL);
    (*tail_ptr)->next = new_node;
    (*tail_ptr) = new_node;
}

void printList(Node** head_ptr) {
    Node* temp = (*head_ptr);
    while(temp != NULL) {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

void rotateList(Node** head_ptr, Node** tail_ptr, int k) {
    Node* temp = (*head_ptr);
    Node* curr = temp;

    for(int i=0; i<k; i++) {
        curr = curr->next;
        (*tail_ptr)->next = temp;
        temp->next = NULL;
        (*tail_ptr) = temp;
        temp = curr;
    }

    (*head_ptr) = curr;
}

void deleteList(Node** head_ptr) {
    Node* temp = (*head_ptr);
    Node* curr = temp;
    while(curr != NULL) {
        curr = curr->next;
        delete temp;
        temp = curr;
    }
}

int main() {
    Node* head = new Node(10, NULL);
    Node* tail = head;

    nodeInsert(&tail, 20);
    nodeInsert(&tail, 30);
    nodeInsert(&tail, 40);
    nodeInsert(&tail, 50);
    nodeInsert(&tail, 60);

    printList(&head);                           // 10 20 30 40 50 60

    rotateList(&head, &tail, 4);
    printList(&head);                           // 50 60 10 20 30 40
    std::cout<<"Head: "<<head->data<<std::endl; // Head: 50
    std::cout<<"Tail: "<<tail->data<<std::endl; // Tail: 40

    deleteList(&head);
    printList(&head);                           // Segmentation fault: 11

    return 0;
}