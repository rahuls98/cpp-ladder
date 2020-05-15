#include <iostream>
#define log(x,y) {std::cout<<x<<" "<<y<<std::endl;}

//Using pointer for incrementing
void inc1(int *n1) {
    (*n1)++;
}

//Using reference for incrementing
void inc2(int &n2) {
    n2++;
}

int main(){
    int a1 = 10;
    int a2 = 10;

    log(a1, a2); //10 10
    inc1(&a1);
    inc2(a2);
    log(a1,a2); //11 11

    return 0;
}