#include <iostream>
#include <vector>

template<typename T, int N>
class Array {
private:
    T arr[N];
public:
    Array(std::vector<T> a) {
        for(int i=0; i<N; i++) arr[i]=a[i];
    }

    int size() { return N; }
    void print() {
        for(int i=0; i<N; i++) std::cout<<arr[i]<<" ";
        std::cout<<std::endl;
    }
};

int main() {
    Array<char, 5> arr({'a','b','c','d','e'}); 
    std::cout<<arr.size()<<std::endl;
    arr.print();

    return 0;
}