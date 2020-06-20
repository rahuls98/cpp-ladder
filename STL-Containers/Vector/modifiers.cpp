#include <iostream>
#include <vector>

#define br() {std::cout<<std::endl;}

int main() {
    std::vector<char> v1;
    v1.assign(3, 'c');

    std::for_each(v1.begin(), v1.end(), [](char c){
        std::cout<<c<<" ";
    });
    br();

    v1.erase(v1.begin(), v1.begin()+1);
    std::cout<<v1.size(); br();

    v1.clear();
    std::cout<<v1.size(); br();

    v1.push_back('a');
    for(char c: v1) std::cout<<c;
    br();

    v1.pop_back();
    std::cout<<v1.size(); br();

    return 0;
}