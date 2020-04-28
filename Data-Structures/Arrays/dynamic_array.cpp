#include <iostream>
#define log(x) {std::cout<<x<<" ";}

int main() {
    int n;
    std::cout<<"Enter number of elements: ";
    std::cin>>n;
    int *a = new int[n];

    for(int i=0; i<n; i++)
        std::cin>>a[i];

    for(int i=0; i<n; i++)
        log(a[i]);

    delete [] a;
    return 0;
}