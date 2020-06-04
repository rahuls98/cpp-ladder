#include <iostream>
#include <array>

#define print(arr) { for(int x: arr) std::cout<<x<<" "; }
#define br() { std::cout<<std::endl; }

int main() {
    std::array<int,3> a = {1,2,3};
    std::array<int,3> b = {10,20,30};

    std::cout<<"a: "; print(a); br(); //a: 1 2 3
    std::cout<<"b: "; print(b); br(); //b: 10 20 30
    br();

    a.swap(b);
    std::cout<<"a: "; print(a); br(); //a: 10 20 30 
    std::cout<<"b: "; print(b); br(); //b: 1 2 3
    br();

    std::array<int,5> c;
    c.fill(5);
    std::cout<<"c: "; print(c); br(); //c: 5 5 5 5 5

    return 0;
}