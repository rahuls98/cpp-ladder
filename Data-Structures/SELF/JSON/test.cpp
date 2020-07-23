#include <iostream>
#include <any>

#define INT std::any_cast<int>

int main() {
    std::any s = 3;
    std::cout<<&INT;

    return 0;
}