#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

void nodeInsert(Node** head_ptr, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    Node* temp = (*head_ptr);
    while(temp->next != NULL) {temp = temp->next;}

    temp->next = new_node;
}

Node* nodeFromEnd(Node** head_ptr, int n) {
    Node* fast = (*head_ptr);
    Node* slow = (*head_ptr);
    int i = 0;
    while(i<n) {
        fast = fast->next;
        i++;
    }

    while(fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
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

    nodeInsert(&head, 20);
    nodeInsert(&head, 30);
    nodeInsert(&head, 40);
    nodeInsert(&head, 50);
    nodeInsert(&head, 60);

    print(&head); // 10 20 30 40 50 60

    int n = 3;
    Node* nthFromBack = nodeFromEnd(&head, n);
    std::cout<<"Node number from end: "<<n<<" and value: "<<nthFromBack->data<<std::endl;
    // Node number from end: 3 and value: 40

    deleteList(&head);
    print(&head); // Segmentation fault: 11

    return 0;
}
