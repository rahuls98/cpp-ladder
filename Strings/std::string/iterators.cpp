#include <iostream>
#include <string>
#include <ctype.h>

#define br() {std::cout<<std::endl;}

int main() {
    std::string s("message");
    std::cout<<s; br();
    
    auto citr = s.cbegin();
    //*citr = 'C'; not possible since cbegin() returns an immutable pointer

    for(auto itr=s.begin(); itr!=s.end(); itr++) {
        *itr = (char)toupper(*itr);
    }

    for(auto c : s) {
        std::cout<<c<<" ";
    }
    br();

    for(auto ritr=s.rbegin(); ritr!=s.rend(); ritr++) {
        std::cout<<*ritr<<" ";
    }
    br();

    return 0;
}