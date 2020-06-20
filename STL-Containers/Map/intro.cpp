#include <iostream>
#include <map>

int main() {
    std::map<int, int> mapper = { {1,1} };
    mapper[0] = 2;
    mapper[2] = 1;

    for(auto p: mapper) {
        std::cout<<p.first<<": "<<p.second<<std::endl;
    }

    return 0;
}