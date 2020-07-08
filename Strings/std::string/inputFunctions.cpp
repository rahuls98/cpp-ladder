#include <iostream>
#include <string>

#define log(x, y) {std::cout<<x<<": "<<y<<std::endl;}

int main() {
    std::string  s1 = "string1";
    log("s1",s1);
    std::string  s2("string2");
    log("s2",s2);
    std::cout<<"Enter 'string4'"<<std::endl;
    std::string s3; getline(std::cin, s3);

    std::cout<<"s3 before push-pop: "<<s3<<std::endl;
    s3.pop_back();
    s3.push_back('3');
    std::cout<<"s3 after push-pop: "<<s3<<std::endl;

    return 0;
}