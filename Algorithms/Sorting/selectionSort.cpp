#include <iostream>
#include <vector>

#define log(x) {std::cout<<x;}
#define print(v) {for(int x: v) {std::cout<<x<<" ";}}
#define br() {std::cout<<std::endl;}

void selectionSort(std::vector<int>::iterator start, std::vector<int>::iterator stop){
    std::vector<int>::iterator itr_i, itr_j, min_ptr;
    int n = 0;
    for(itr_i=start; itr_i<stop; itr_i++) {
        int min = *(start+n);
        min_ptr = start+n;

        for(itr_j=start+n; itr_j<stop; itr_j++){
            if((*itr_j) < min) {
                min=(*itr_j);
                min_ptr = itr_j;
            }
        }

        int temp = (*itr_i);
        (*itr_i) = min;
        (*min_ptr) = temp;

        n++;
    }
}

int main() {
    std::vector<int> v = {64, 25, 12, 22, 11};

    log("Original vector: "); print(v); br();   // Original vector: 64 25 12 22 11
    selectionSort(v.begin(), v.end());
    log("Sorted vector: "); print(v); br();     // Sorted vector: 11 12 22 25 64

    return 0;
}