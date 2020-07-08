#include <iostream>
#include <string>

#define log(x,y) {std::cout<<x<<y<<std::endl;}
#define br() {std::cout<<std::endl;}

int main() {
    std::string s;
    //** max_size
    log("String max size: ", s.max_size());
    //** empty **
    log("String empty? ", s.empty());
    log("string: ", s);

    s = "message";
    log("String empty? ", s.empty());
    log("string: ", s);
    br();

    //** size **
    log("Size: ", s.size());
    //** length **
    log("Length: ", s.length());
    //** Distance **
    log("Distance: ", std::distance(std::begin(s), std::end(s)));
    br();

    return 0;
}