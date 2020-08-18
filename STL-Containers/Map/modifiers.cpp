#include <iostream>
#include <map>

int main() {
    std::map<int,char> mapper = {};
    mapper.insert({1,'a'});
    mapper.insert({2,'b'});
    mapper.insert({3,'c'});

    for(auto &p: mapper) {
        std::cout<<p.first<<": "<<p.second<<std::endl;;
    }

    return 0;
}
