#include <iostream>
#include <map>

#define br() {std::cout<<std::endl;}

void print(std::map<int,int> container) {
    std::cout<<"{ ";
    for(std::pair<int,int> x: container) {
        std::cout<<x.first<<": "<<x.second<<", ";
    }
    std::cout<<"}";
}

int main() {
    std::map<int, int> mapper = { {1,1} };
    mapper[0] = 2;
    mapper[2] = 1;

    print(mapper); br();

    int& ref = mapper.at(0);
    ref = 5;

    print(mapper); br();

    return 0;
}