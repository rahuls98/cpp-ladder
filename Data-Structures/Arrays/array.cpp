#include <iostream>
#define log(x,y) {std::cout<<x<<y<<std::endl;}

int main() {
    int arr[5];
    int n = sizeof(arr)/sizeof(int);

    for(int i=0; i<n; i++){
        std::cin>>arr[i];
    }

    log("arr[1]: ",arr[1]);
    log("*(arr+1): ",*(arr+1));

    return 0;
}