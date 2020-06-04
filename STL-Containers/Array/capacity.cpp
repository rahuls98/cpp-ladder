#include <iostream>
#include <array>

int main() {
    std::array<int, 0> a1;
    std::array<std::string, 2> s1 = { std::string("abc"), "123" };

    std::cout<<a1.empty()<<std::endl; //1
    std::cout<<s1.size()<<std::endl; //2
    std::cout<<s1.max_size()<<std::endl; //2

    return 0;
}