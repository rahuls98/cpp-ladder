#include <iostream>

int main() {
    int nums[2][3]  =  { {16, 18, 20}, {25, 26, 27} };

    // *(*(arr+i)+j) -> access dimensions inside out 
    std::cout<< *(*(nums)) <<std::endl;
    std::cout<< *(*(nums) + 1) <<std::endl;
    std::cout<< *(*(nums) + 2) <<std::endl;

    std::cout<< *(*(nums + 1)) <<std::endl;
    std::cout<< *(*(nums + 1) + 1) <<std::endl;
    std::cout<< *(*(nums + 1) + 2) <<std::endl;

    return 0;
}