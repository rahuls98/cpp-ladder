#include <vector>
#include <iostream>

#define VITR std::vector<int>::iterator
#define LOG(x) std::cout<<x<<": ";
#define PRINT(X) {for(int x:X) {std::cout<<x<<" ";}}
#define BR() std::cout<<std::endl;

void merge(VITR a_start, VITR a_end, VITR b_start, VITR b_end) {
    std::vector<int> a(a_start, a_end);
    std::vector<int> b(b_start, b_end);
    
    VITR i,j,k;
    i = a.begin();
    j = b.begin();
    k=a_start;

    while(i!=a.end() && j!=b.end()) {
        if((*i) < (*j)) {
            (*k) = (*i);
            k++; i++;
        } else {
            (*k) = (*j);
            k++; j++;
        }
    }

    if(i==a.end()) {
        while(j!=b.end()) {
            (*k) = (*j);
            k++; j++;
        }
    } else {
        while(i!=a.end()) {
            (*k) = (*i);
            k++; i++;
        }
    }
}

void mergeSort(VITR start, VITR end, int n) {
    if(n > 1) {
        int m = n/2;
        mergeSort(start, start+m, m);
        mergeSort(start+m, end, n-m);
        merge(start, start+m, start+m, end);
    }
}

int main() {
    std::vector<int> v = { 15, 1, 2, 12, 11, 13, 5, 2, 7, 3 };

    LOG("Original vector"); PRINT(v); BR();     // Original vector: 15 1 2 12 11 13 5 2 7 3
    mergeSort(v.begin(), v.end(), v.size());
    LOG("Sorted vector"); PRINT(v); BR();       // Sorted vector: 1 2 2 3 5 7 11 12 13 15

    return 0;
}