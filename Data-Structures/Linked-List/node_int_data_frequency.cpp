#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> frequency = {};

class Node {
    public: 
        int data;
        Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

void traverse(Node** head_ptr) {
    Node* temp = (*head_ptr);
    while(temp != NULL) {
        if(frequency[temp->data] == 0) 
            frequency[temp->data]=1;
        else 
            frequency[temp->data] += 1;

        temp = temp->next;
    }

    std::cout<<"{ ";
    for(auto x: frequency) { std::cout<<x.first<<": "<<x.second<<" "; }
    std::cout<<" }"<<std::endl;
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
    Node* last = new Node(50, NULL);
    Node* sixth = new Node(40, last);
    Node* fifth = new Node(20, sixth);
    Node* fourth = new Node(10, fifth);
    Node* third = new Node(30, fourth);
    Node* second = new Node(20, third);
    Node* head = new Node(10, second);

    traverse(&head); // { 50: 1 40: 1 30: 1 20: 2 10: 2  }
    std::cout<<"\nFrequency of 20: "<<frequency[20]<<std::endl; // Frequency of 20: 2

    deleteList(&head); print(&head); // Segmentation fault: 11

    return 0;
}