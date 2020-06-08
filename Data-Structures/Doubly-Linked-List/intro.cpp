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
    int i = 1;
    while(ptr != NULL) {
        std::cout<<"Node "<<i<<": ";
        
        if(ptr->prev == NULL) std::cout<<"PREV[ NULL ]"<<" \t<-> ";
        else std::cout<<"PREV[ "<<ptr->prev->data<<" ] \t<-> ";

        std::cout<<"\tCURR[ "<<ptr->data<<" ] \t<-> ";

        if(ptr->next == NULL) std::cout<<"\tNEXT[ NULL ]";
        else std::cout<<"\tNEXT[ "<<ptr->next->data<<" ] ";

        std::cout<<std::endl;

        ptr = ptr->next;
        i += 1;
    }

    return 0;
}