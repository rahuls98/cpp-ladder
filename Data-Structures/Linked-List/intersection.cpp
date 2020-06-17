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

void traverse(Node** head_ptr) {
    Node* temp = (*head_ptr);
    while(temp != NULL) {
        visited[temp] = true;
        temp = temp->next;
    }

    /* for(auto x: visited) {
        std::cout<<x.first<<": "<<x.second<<" ";
    } */
}

Node* getIntersection(Node** head1, Node** head2) {
    traverse(head1);
    Node* temp = (*head2);
    while(temp != NULL) {
        if(visited[temp]) {
            return temp;
        }

        else temp=temp->next;
    }

    return NULL;
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
    Node* l15 = new Node(50, NULL);
    Node* l14 = new Node(40, l15);
    Node* l13 = new Node(30, l14);
    Node* l12 = new Node(20, l13);
    Node* l11 = new Node(10, l12);
    print(&l11); // 10 20 30 40 50

    Node* l22 = new Node(30, l14);
    Node* l21 = new Node(20, l22);
    print(&l21); // 20 30 40 50

    Node* intersection;
    intersection = getIntersection(&l11, &l22);
    if(intersection == NULL) std::cout<<"\nNo intersection";
    else std::cout<<"\nIntersection node: "<<intersection->data; // Intersection node: 40

    std::cout<<std::endl;

    deleteList(&l11); print(&l11);
    deleteList(&l21); print(&l21); // Segmentation fault: 11

    return 0;
}