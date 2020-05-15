#include <iostream>
#include <cassert>

void logger(int *ptr) {
    assert(ptr != NULL);
    std::cout<<*ptr<<std::endl;
}

int main() {
    int *a = NULL;
    int *b = NULL;
    int p = 100;

    a = &p;

    logger(a); //100
    logger(b); //Assertion failed: (ptr != NULL), function logger, file assert.cpp, line 6.

    return 0;
}