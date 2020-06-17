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

void deleteUsingKey(Node** head_ptr, int key) {
    Node* temp = (*head_ptr);
    if(temp->data == key) {
        (*head_ptr)=temp->next;
        return;
    }

    while(temp != NULL) {
        if(temp->next == NULL) break;

        if(temp->next->data == key) {
            //LAST NODE
            if(temp->next->next == NULL) {
                temp->next = NULL;
                return;
            }

            temp->next = temp->next->next;
            return;
        }

        temp = temp->next;
    }

    std::cout<<"Key not present: "<<key<<std::endl;
}

void print(Node** head_ref) {
    Node* temp = (*head_ref);
    while(temp != NULL) {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

int main() {
    Node* last = new Node(40, NULL);
    Node* third = new Node(30, last);
    Node* second = new Node(20, third);
    Node* head = new Node(10, second);

    print(&head); // 10 20 30 40
    deleteUsingKey(&head, 10); print(&head); // 20 30 40
    deleteUsingKey(&head, 30); print(&head); // 20 40
    deleteUsingKey(&head, 40); print(&head); // 20
    deleteUsingKey(&head, 50); // Key not present: 50
    print(&head); // 20

    return 0;
}