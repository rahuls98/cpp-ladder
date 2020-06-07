#include <iostream>
#include <vector>

#define print(x,y) { std::cout<<x<<": "<<y; }
#define br() { std::cout<<std::endl; }

int main() {
    std::vector<int> v1 = { 1,2,3 };

    int &a = v1.at(1);
    print("at(1)", a); br(); // at(1): 2
    print("[1]", v1[1]); br(); // [1]: 2

    int &front = v1.front();
    print("front", front); br(); // front: 1
    int &back = v1.back();
    print("back", back); br(); // back: 3

    return 0;
}