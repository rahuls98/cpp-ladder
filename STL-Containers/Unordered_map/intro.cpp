#include <iostream>
#include <unordered_map>

#define br() {std::cout<<std::endl;}

void print(std::unordered_map<int,int> container) {
    std::cout<<"{ ";
    for(std::pair<int,int> x: container) {
        std::cout<<x.first<<": "<<x.second<<", ";
    }
    std::cout<<"}";
}

int main() {
    std::unordered_map<int, int> mapper = { {1,1} };
    mapper[0] = 2;
    mapper[2] = 1;

    print(mapper); br();        // { 1: 1, 0: 2, 2: 1, }

    int& ref = mapper.at(0);
    ref = 5;
    mapper[2] = 2;

    print(mapper); br();        // { 1: 1, 0: 5, 2: 2, }

    return 0;
}