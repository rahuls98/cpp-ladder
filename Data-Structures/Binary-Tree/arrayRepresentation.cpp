#include <iostream>

#define log(x,y) { std::cout<<x<<y<<std::endl; }
#define br() { std::cout<<std::endl; }
int binTree[10];

bool findNode(int data) {
    int n = sizeof(binTree)/sizeof(binTree[0]);
    for(int i=0; i<n; i++) {
        if(binTree[i] == data) {
           log("Parent node: ", binTree[i]);

           if(((2*i) + 1) < n) {log("Left child: ", binTree[(2*i) + 1]);}
           else {log("Left child: ", "NULL");}

           if(((2*i) + 2) < n) {log("Right child: ", binTree[(2*i) + 2]);}
           else {log("Right child: ", "NULL");}

           return true;
        }
    }

    return false;
}

int main() {
    int choice;

    br();
    std::cout<<"Enter Binary Tree in Level Order: ";
    for(int i=0; i<10; i++) std::cin>>binTree[i];

    while(true) {
        br();
        std::cout<<"Enter parent node (-1 to exit): ";
        std::cin>>choice;

        if(choice == -1) break;

        if(!findNode(choice)) 
            std::cout<<"Invalid node!"<<std::endl; 
    }

    return 0;
}