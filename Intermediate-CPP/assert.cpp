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

    logger(a);
    logger(b);

    return 0;
}