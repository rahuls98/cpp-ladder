#include <iostream>
#include <queue> 
  
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0])) 
  
class Node {  
public: 
    int data;  
    Node *next = NULL;  
    Node *child = NULL;  
};  

std::queue<Node*> childTracker;
  
Node *createList(int *arr, int n) {  
    Node *head = NULL;  
    Node *p;  
    for(int i = 0; i < n; ++i) {  
        if (head == NULL)  
            head = p = new Node(); 
        else {  
            p->next = new Node(); 
            p = p->next;  
        }  
        p->data = arr[i];  
        p->next = p->child = NULL;  
    }  
    return head;  
}  

Node *createList(void) {  
    int arr1[] = {10, 5, 12, 7, 11};  
    int arr2[] = {4, 20, 13};  
    int arr3[] = {17, 6};  
    int arr4[] = {9, 8};  
    int arr5[] = {19, 15};  
    int arr6[] = {2};  
    int arr7[] = {16};  
    int arr8[] = {3};  
  
    Node *head1 = createList(arr1, SIZE(arr1));  
    Node *head2 = createList(arr2, SIZE(arr2));  
    Node *head3 = createList(arr3, SIZE(arr3));  
    Node *head4 = createList(arr4, SIZE(arr4));  
    Node *head5 = createList(arr5, SIZE(arr5));  
    Node *head6 = createList(arr6, SIZE(arr6));  
    Node *head7 = createList(arr7, SIZE(arr7));  
    Node *head8 = createList(arr8, SIZE(arr8));  
  
    head1->child = head2;  
    head1->next->next->next->child = head3;  
    head3->child = head4;  
    head4->child = head5;  
    head2->next->child = head6;  
    head2->next->next->child = head7;  
    head7->child = head8;  
  
    return head1;  
}  
  
void flattenList(Node** head_ptr) {  
    Node* temp = (*head_ptr);
    Node* curr = temp;
    Node* last;
    do {
        while(curr!= NULL) {
            if(curr->next == NULL) last=curr;

            if(curr->child != NULL) childTracker.push(curr->child);

            curr = curr->next;
        }

        temp = childTracker.front();
        last->next = temp;
        childTracker.pop();
        curr = temp;

    } while(!childTracker.empty());
}

void printList(Node** head_ptr) {
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
    Node* head = NULL;  
    head = createList(); 

    flattenList(&head);  
    printList(&head);   // 10 5 12 7 11 4 20 13 17 6 2 16 9 8 3 19 15
    delList(&head);
    printList(&head);   // Segmentation fault: 11

    return 0;  
} 