#include <iostream>
#include <vector>
#include <iterator>

#define br() {std::cout<<std::endl;}

int main() {
    std::vector<int> v1 = { 10, 20, 30 };

    std::vector<int>::iterator itr;
    for(itr=v1.begin(); itr!=v1.end(); itr++)
        std::cout<<*itr<<" "; // 10 20 30
    br();

    std::for_each(v1.rbegin(), v1.rend(), [](int x){
        std::cout<<x<<" "; // 30 20 10
    });
    br();

    return 0;
}