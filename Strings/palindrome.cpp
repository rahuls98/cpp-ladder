#include <iostream>
#include <string>
#include <cassert>

#define log(x) { std::cout<<x<<std::endl; }

int main() {
    std::string inp;
    while(true) {
        std::cout<<"Enter input string: "<<std::endl;
        std::cin>>inp;

        assert(inp != "exit");

        if(inp == std::string( inp.rbegin(), inp.rend())) {log("PALINDROME!");}
        else {log("NOT PALINDROME!");}
    }

    return 0;
}