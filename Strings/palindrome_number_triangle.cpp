'''

--Input--
5

--Output-- 
5
454
34543
2345432
123454321
2345432
34543
454
5

'''

#include <iostream>
#include <string>
#define log(x) {std::cout<<x<<std::endl;}

int main() {
    int i,n;
    std::cout<<"Enter number: ";
    std::cin>>n;
    std::string s = "";

    s += std::to_string(n);
    log(s);

    for(i=n-1; i>=1; i--) {
        std::string temp = std::to_string(i);
        s = temp + s;
        s = s + temp;
        log(s);
    }
    while(s.size()>0) {
        s.erase(0, 1);
        s.pop_back();
        log(s);
    }
}