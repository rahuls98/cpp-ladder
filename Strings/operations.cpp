#include <iostream>
#include <iomanip>
#include <string>
#define log(x,y) {std::cout<<x<<y<<std::endl;}
#define br() {std::cout<<std::endl;}

int main() {
    std::cout<<std::quoted("String operations");
    br();br();

    std::string s = "This is my message";
    log("String: ", s);
    log("String size: ", s.size());
    br();

    //** clear **
    s.clear();
    log("String size after clear: ", s.size());
    br();

    s = "This is my message";
    //** erase **
    s.erase(8, 3);
    log("String after erase 1: ", s);
    s.erase( std::find(s.begin(), s.end(), ' ') );
    log("String after erase 2: ", s);
    s.erase(s.find(' '));
    log("String after erase 3: ", s);
    br();

    log("String size: ", s.size());
    s.pop_back();
    log("String after pop-back: ", s);
    s.push_back((int)toupper('s'));
    log("String after push-back: ", s);
    br();

    s += " my";
    s += {' ','m','e','s','s','a','g','e'};
    log("String: ", s);
    br();

    return 0;
}