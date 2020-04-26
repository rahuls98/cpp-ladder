#include <iostream>
#define log(x,y) {std::cout<<x<<y<<std::endl;}

int main() {
    //variable declaration
    int var = 5;

    //reference creation
    int &ref = var;

    //pointer creation
    int *ptr = &var;

    log("Variable value: ",var);
    log("Reference value: ",ref);
    log("Variable address: ",&var);
    log("Reference address: ",&ref);
    log("Pointer value: ",ptr);
    log("Pointer dereference: ",*ptr);
    
    return 0;
}