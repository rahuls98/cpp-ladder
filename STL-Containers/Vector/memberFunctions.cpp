#include <iostream>
#include <vector>

#define print(vector) { for(int x: vector) std::cout<<x<<" "; }
#define br() { std::cout<<std::endl; } 

int main() {
    std::vector<int> v1 {1,2,3};
    std::vector<int> v2 = {10,20,30};
    std::vector<char> v3;

    v3.assign(5, 'c');

    print(v1); br(); //1 2 3
    print(v2); br(); //10 20 30

    std::for_each(v3.begin(), v3.end(), [](char c) {
        std::cout<<c<<" "; //c c c c c
    }); br();

    return 0;
}