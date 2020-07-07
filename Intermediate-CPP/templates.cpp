#include <iostream>
#include <vector>

template<typename T, int N>
class Array {
private:
    T arr[N];
public:
    Array(std::vector<T> a) {
        int n = a.size();
        int i,j;

        // argument list size exceeds allowed size.
        if(n>N) { 
            for(i=0; i<N; i++) arr[i]=a[i];
        }
        else {
            for(i=0; i<n; i++) arr[i]=a[i];

            // argument list size less than allowed size.
            if(n<N) {
                for(j=i; j<N; j++) arr[j]='\0';
            }
        }
    }

    int size() { return N; }

    void print() {
        for(int i=0; i<N; i++) std::cout<<arr[i]<<" ";
        std::cout<<std::endl;
    }
};

int main() {
    Array<char, 5> arr1({ 'a','b','c','d','e' }); 
    std::cout<<arr1.size()<<std::endl;   // 5
    arr1.print();                        // a b c d e

    Array<int, 5> arr2({ 1,2,3,4,5 }); 
    std::cout<<arr2.size()<<std::endl;   // 5
    arr2.print();                        // 1 2 3 4 5

    return 0;
}