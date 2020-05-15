#include <iostream>
#define log(x,y) {std::cout<<x<<y<<std::endl;}

int main() {
    //variable declaration
    int var = 5;

    //reference creation
    int &ref = var;

    //pointer creation
    int *ptr = &var;

    log("Variable value: ",var); //Variable value: 5
    log("Reference value: ",ref); //Reference value: 5
    log("Variable address: ",&var); //Variable address: 0x7ffeea609aa8
    log("Reference address: ",&ref); //Reference address: 0x7ffeea609aa8
    log("Pointer value: ",ptr); //Pointer value: 0x7ffeea609aa8
    log("Pointer dereference: ",*ptr); //Pointer dereference: 5
    
    return 0;
}