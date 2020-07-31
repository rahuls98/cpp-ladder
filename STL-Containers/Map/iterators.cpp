#include <iostream>
#include <map>

int main() {
    std::map<int, char> mapper = {
        {3,'c'},
        {1,'a'},
        {2,'b'}
    };

    for(auto p=mapper.begin(); p!=mapper.end(); p++) {
        std::cout<<p->first<<": "<<p->second<<std::endl;
    }
    /*
        1: a
        2: b
        3: c
    */

    std::cout<<std::endl;

    for(auto p=mapper.rbegin(); p!=mapper.rend(); p++) {
        std::cout<<p->first<<": "<<p->second<<std::endl;
    }
    /*
        3: c
        2: b
        1: a
    */

    return 0;
}