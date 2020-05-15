#include <iostream>
#define log(x, y) {std::cout<<x<<": "<<y<<std::endl;}

int main() {
    /* creating and allocating required memory in heap */
    int *ptr = new int;
    log(ptr, *ptr); //0x7fbf0e401820: 0

    /* setting value in the memory location */
    *ptr = 5;
    log(ptr, *ptr); //0x7fbf0e401820: 5

    /* free dynamically allocated memory */
    delete ptr;
    log(ptr, *ptr); //0x7fbf0e401820: 5

    /* handle the dangling pointer */
    ptr = NULL;
    log(ptr, *ptr); //Segmentation fault: 11

    return 0;
}