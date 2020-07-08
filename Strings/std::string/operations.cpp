#include <iostream>
#include <iomanip>
#include <string>
#define log(x,y) {std::cout<<x<<y<<std::endl;}
#define br() {std::cout<<std::endl;}

int main() {
    std::cout<<std::quoted("String operations");
    br();br();

    std::string s = "This is my message";
    log("String: ", s); //String: This is my message
    log("String size: ", s.size()); //String size: 18
    br();

    //** clear **
    s.clear();
    log("String size after clear: ", s.size()); //String size after clear: 0
    br();

    s = "This is my message";
    //** erase **
    s.erase(8, 3);
    log("String after erase 1: ", s); //String after erase 1: This is message
    s.erase( std::find(s.begin(), s.end(), ' ') );
    log("String after erase 2: ", s); //String after erase 2: Thisis message
    s.erase(s.find(' '));
    log("String after erase 3: ", s); //String after erase 3: Thisis
    br();

    log("String size: ", s.size()); //String size: 6
    s.pop_back();
    log("String after pop-back: ", s); //String after pop-back: Thisi
    s.push_back((int)toupper('s'));
    log("String after push-back: ", s); //String after push-back: ThisiS
    br();

    s += " my";
    s += {' ','m','e','s','s','a','g','e'};
    log("String: ", s); //String: ThisiS my message
    br();

    s.replace(5, 1, "s");
    log("Replace using position: ", s); //Replace using position: Thisis my message
    s.replace(s.begin(), s.begin()+6, "This is");
    log("Replace using iterator: ", s); //Replace using iterator: This is my message
    br();

    return 0;
}