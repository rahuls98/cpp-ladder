#include <iostream>
#include <string>

#define log(x,y) {std::cout<<x<<y<<std::endl;}
#define br(x) {std::cout<<std::endl;}

int main() {
    std::string s("message");
    s = "abc";
    s[2] = 'x';
    log("stating string: ",s);
    br();

    std::cout<<"** at **"<<std::endl;
    //returns reference to requested character
    //std::out_of_range thrown if position exceeds range
    char &ref = s.at(2);
    log("referenced value: ",ref);
    ref = 'c';
    log("after mutation: ",s);
    br();

    std::cout<<"** front **"<<std::endl;
    //returns reference to first character
    char &f = s.front();
    log("first character: ", f);
    f = 'A';
    log("after mutation: ",s);
    br();

    std::cout<<"** back **"<<std::endl;
    //returns reference to last character
    char &b = s.back();
    log("last character: ", b);
    b = 'C';
    log("after mutation: ",s);
    br();

    std::cout<<"** data **"<<std::endl;
    //returns pointer to the underlying character storage 
    //[internal array currently used by the string object]
    const char *ptr1 = s.data();
    log("data: ",ptr1);
    std::cout<<"characters: ";
    for(int i=0; *(ptr1 + i)!='\0'; i++) {
        std::cout<<*(ptr1 + i)<<" ";
    }
    br();br();

    std::cout<<"** c_str **"<<std::endl;
    //pointer to a null-terminated character array with data equivalent to those stored in the string.
    const char *ptr2 = s.c_str();
    log("c_str: ", ptr2);
    std::cout<<"characters: ";
    for(int i=0; *(ptr2 + i)!='\0'; i++) {
        std::cout<<*(ptr2 + i)<<" ";
    }
    br();

    return 0;
}