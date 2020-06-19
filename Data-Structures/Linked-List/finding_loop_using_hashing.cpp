#include <iostream>
#include <string>
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
    Node* temp = (*head_ptr);
    while(temp != NULL) {
        if(visited[temp]) 
            return temp;
        else {
            visited[temp] = true;
            temp = temp->next;
        }  
    }
}

int main() {
    Node* last = new Node(20, NULL);
    Node* third = new Node(4, last);
    Node* second = new Node(15, third);
    Node* head = new Node(10, second);

    last->next = second;

    Node* loopNode = findLoop(&head);
    std::cout<<"Loop begins at node: "<<loopNode<<" with data: "<<loopNode->data<<std::endl;

    delete head;
    delete second;
    delete third;
    delete last;
}