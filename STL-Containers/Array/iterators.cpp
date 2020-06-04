#include <iostream>
#include <iterator>
#include <array>

#define br() { std::cout<<std::endl; }

int main() {
    std::array<int, 5> a1 = { 1,2,3,4,5 };
    std::array<int, 5>::iterator itr;

    for(itr=a1.begin(); itr!=a1.end(); itr++) 
        std::cout<<*itr<<" "; // 1 2 3 4 5
    br();

    std::for_each(a1.rbegin(), a1.rend(), [](int x) { 
        std::cout<<x<<" "; // 5 4 3 2 1
    });
    br();

    return 0;
}