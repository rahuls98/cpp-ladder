#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, char> mapper = {
        {1,'a'},
        {2,'b'}
    };

    auto res = mapper.find(2);

    if(res!=mapper.end()) {
        std::cout<<"Found "<<res->first<<": "<<res->second<<std::endl;
    } else {
        std::cout<<"Pair not present!"<<std::endl;
    }

    return 0;
}