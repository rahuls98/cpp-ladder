#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, char> mapper = {
        {3,'c'},
        {1,'a'},
        {2,'b'}
    };

    for(auto p=mapper.begin(); p!=mapper.end(); p++) {
        std::cout<<p->first<<": "<<p->second<<std::endl;
    }
    /*
        2: b
        1: a
        3: c
    */

    // No reverse reverse iterator functionality!

    return 0;
}