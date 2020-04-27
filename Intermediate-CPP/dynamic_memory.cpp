#include <iostream>
#define log(x, y) {std::cout<<x<<": "<<y<<std::endl;}

int main() {
    //creating and allocating required memory in heap
    int *ptr = new int;
    log(ptr, *ptr);

    //setting value in the memory location
    *ptr = 5;
    log(ptr, *ptr);

    //free dynamically allocated memory
    delete ptr;
    log(ptr, *ptr);

    //handle the dangling pointer
    ptr = NULL;
    log(ptr, *ptr);

    return 0;
}