#include <iostream>
#include <array>
#include <string>

#define print(arr) { for(auto x : arr) std::cout<<x<<" "; } 
#define log(x) { std::cout<<x; }
#define br() { std::cout<<std::endl; }

int main() {
    std::array<int, 3> a1 = {1,2,3};
    std::array<std::string, 2> s1 = { std::string("abc"), "123" };

    print(a1); br(); //1 2 3
    print(s1); br(); //abc 123 

    std::cout<<a1[1]; br(); //2
    int &ref = a1.at(1);
    ref = 4;
    print(a1); br(); //1 4 3

    log(a1.front()); br(); //1
    log(s1.back()); br(); //123

    return 0;
}