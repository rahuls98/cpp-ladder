#include <iostream>
#include <vector>

#define log(x) {std::cout<<x;}
#define print(v) {for(int x: v) {std::cout<<x<<" ";}}
#define br() {std::cout<<std::endl;}

void merge(std::vector<int> a, std::vector<int> b) {
    log("Merge: "); print(a); log("|| "); print(b); br();
}

void mergeSort(std::vector<int> v) {
    if( v.size()==1 ) {
        return;
    } else {
        int m = v.size()/2;
        std::vector<int> a,b;
        for(int i=0; i<m; i++) a.push_back(v[i]);
        for(int i=m; i<v.size(); i++) b.push_back(v[i]);

        mergeSort(a);
        mergeSort(b);
        merge(a,b);
    }     
}

int main() {
    std::vector<int> vec = { 8,3,2,9,7,1,5,4 };
    
    log("Original vector: "); print(vec); br(); 
    mergeSort(vec);

    return 0;
}