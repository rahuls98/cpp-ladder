#include <iostream>
#include <vector>

#define log(x) {std::cout<<x;}
#define print(v) {for(auto x:v) {std::cout<<x<<" ";}}
#define br() {std::cout<<std::endl;}

void bubbleSort(std::vector<int>::iterator start, std::vector<int>::iterator stop) {
    std::vector<int>::iterator itr_i, itr_j;
    for(itr_i=start; itr_i<stop-1; itr_i++) {
        bool change = false;
        for(itr_j=start; itr_j<stop-1; itr_j++) {
            if((*itr_j) > *(itr_j + 1)){
                int temp = (*itr_j);
                (*itr_j) = *(itr_j + 1);
                *(itr_j + 1) = temp;
                change = true;
            }
        }

        if(change == false) break;
    }
}

int main() {
    std::vector<int> v = {64, 34, 25, 12, 22, 11, 90};

    log("Original vector: "); print(v); br();   // Original vector: 64 34 25 12 22 11 90
    bubbleSort(v.begin(), v.end());
    log("Sorted vector: "); print(v); br();     // Sorted vector: 11 12 22 25 34 64 90

    return 0;
}