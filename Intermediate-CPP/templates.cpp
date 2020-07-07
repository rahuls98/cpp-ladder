#include <iostream>

template<typename T, int N>
class Array {
private:
    T arr[N];
public:
    int size() { return N; }
    void print() {
        for(int i=0; i<N; i++) std::cout<<arr[i]<<" ";
        std::cout<<std::endl;
    }
};

int main() {
    Array<char, 5> arr; 
    std::cout<<arr.size()<<std::endl;

    return 0;
}
