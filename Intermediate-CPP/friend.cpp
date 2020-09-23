#include <iostream>
#include <string>

#define LOG(x) {std::cout << x << std::endl;}

class Temp
{
    std::string s;

public:
    Temp() : s{"Hello!"} {}
    Temp(std::string str) : s{str} {}
    friend void getter(Temp&); 
    void setter(std::string);
};

void getter(Temp& obj) { LOG(obj.s); }
void Temp::setter(std::string str) { this->s = str; }

int main()
{
    Temp obj1;
    Temp obj2("Hello world!");

    getter(obj1);
    getter(obj2);

    obj1.setter("Let's start!");
    getter(obj1);

    return 0;
}