#include <iostream>
#include <map>

std::map<int, int> mapper;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

void insertNode(Node** head_ptr, int new_data) {
    Node* new_node = new Node(new_data, NULL);
    Node* temp = (*head_ptr);
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void sortList(Node** head_ptr) {
    Node* temp = (*head_ptr);
    while(temp != NULL) {
    }
}

void print(Node** head_ptr) {
    Node* temp = (*head_ptr);
    while(temp != NULL) {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

void delList(Node** head_ptr) {
    Node* temp = (*head_ptr);
    Node* curr = temp;
    while(curr != NULL) {
        curr = temp->next;
        delete temp;
        temp = curr;
    }
}

int main() {
    Node* head = new Node(1, NULL);
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 0);
    insertNode(&head, 2);
    insertNode(&head, 0);
    insertNode(&head, 1);

    print(&head);
    sortList(&head);

    delList(&head);
    print(&head);
}