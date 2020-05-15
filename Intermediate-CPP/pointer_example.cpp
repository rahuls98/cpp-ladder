#include <iostream>

int main() {
    int arr[3][3] = { { 1,2,3 },
                      { 4,5,6 },
                      { 7,8,9 } };

    int res = ( *(*(arr+1)+2) * *(*(arr+1)+0) * (*(*(arr+2)+1) + *(arr[1]+2)) );
    std::cout<<res<<std::endl; //(6 * 4 * (8+6)) = 336

    return 0;
}