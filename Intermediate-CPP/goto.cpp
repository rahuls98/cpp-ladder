#include <iostream>

int main() {
    if(false) {
        // true -> label_1 -> label_2
        label_1 : std::cout<<"Hello ";
        goto label_2;
    } else {
        // false -> label_1 -> label_2
        goto label_1;
        label_2: std::cout<<"World!";
    }

    std::cout<<std::endl;
    return 0;
}