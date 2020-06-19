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

Node* findLoop(Node** head_ptr) {
    Node *slow, *fast;
    slow = fast = (*head_ptr);

    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) return slow;
    }

    return NULL;
}

int main() {
    Node* last = new Node(20, NULL);
    Node* third = new Node(4, last);
    Node* second = new Node(15, third);
    Node* head = new Node(10, second);

    last->next = second;

    Node* loopNode = findLoop(&head);

    if(loopNode == NULL) 
        std::cout<<"No loop in Linked List!"<<std::endl;
    else
        std::cout<<"Loop found in Linked List!"<<std::endl;

    delete head;
    delete second;
    delete third;
    delete last;
}