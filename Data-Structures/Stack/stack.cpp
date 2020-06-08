#include <iostream>

#define log(x) { std::cout<<x; }
#define br() { std::cout<<std::endl; }

int *arr;
int n;
int top = -1;

bool push(int ele) {
    if(top == n-1) {
        log("Stack full!"); br();
        return false;
    } 

    arr[++top] = ele;
    return true;
}

int pop() {
    if(top == -1) {
        log("Stack empty!"); br();
        return -1;
    }

    int popped = arr[top];
    arr[top--] = 0;
    return popped;
}

void print() {
    for(int i=0; i<n; i++)
        std::cout<<arr[i]<<" ";

    br();
}

int main() {
    std::cout<<"Enter max stack size: ";
    std::cin>>n;

    arr = new int[n];
    for(int i=0; i<n; i++){
        arr[i] = 0;
    }
    print();

    while(true) {
        int choice;
        br();br();
        log("---Menu---"); br();
        log("1. Push"); br();
        log("2. Pop"); br();
        log("3. Print"); br();
        log("4. Exit"); br();

        log("Enter choice: ");
        std::cin>>choice; br();

        int ele, popped;
        switch(choice) {
            case 1: 
                log("Enter element to be inserted: ");
                std::cin>>ele;
                if(push(ele)) {
                    log("Push complete: "); print();
                }
                break;
            case 2:
                popped = pop();
                if(popped==-1) {
                    log("Popped element: "); log("NONE");
                }
                else {
                    log("Pop complete: "); print();
                    log("Popped element: "); log(popped);
                } 
                break;
            case 3:
                log("Stack: "); print();
                break;
            case 4:
                log("Exiting!"); br();
                delete [] arr;
                exit(0);
            default:
                log("Invalid choice! Try again");
                break;
        }
    }

    return 0;
}