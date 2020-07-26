#include <iostream>
#include <vector>

template <typename T>
void mean(std::vector<T> args) {
    std::cout<<"Mean of args: ";
    int n = args.size();

    if(n==0) std::cout<<"UNDEFINED"<<std::endl;
    else if(n==1) std::cout<<args[0]<<std::endl;
    else {
        double total = 0;
        for(auto ele: args) total += ele;
        std::cout<<(total/n)<<std::endl;
    }
}

int main() {
    mean<double>({});                       // Mean of args: UNDEFINED
    mean<int>({ 10 });                      // Mean of args: 10
    mean<int>({ 1, 2, 3, 4, 5 });           // Mean of args: 3 
    mean<double>({ 1.54, 2.53, 6.12 });     // Mean of args: 3.39667

    return 0;
}