#include <iostream>
#include <vector>

#define log(x) {std::cout<<x;}
#define print(v) {for(int x: v) {std::cout<<x<<" ";}}
#define br() {std::cout<<std::endl;}

void insertionSort(std::vector<int>::iterator start, std::vector<int>::iterator stop) {
    std::vector<int>::iterator itr_i, itr_j;
    int temp;
    
    for(itr_i=(start+1); itr_i<stop; itr_i++) {
        temp = (*itr_i);

        for(itr_j=(itr_i-1); itr_j>=start; itr_j--) {
            if(temp < (*itr_j)) {
                *(itr_j+1) = (*itr_j);
                (*itr_j) = temp;
            }
        }
    } 
}

int main() {
    std::vector<int> v = { 12, 11, 13, 5, 6 };

    log("Original vector: "); print(v); br();   // Original vector: 12 11 13 5 6 
    insertionSort(v.begin(), v.end());
    log("Sorted vector: "); print(v); br();     // Sorted vector: 5 6 11 12 13

    return 0;
}