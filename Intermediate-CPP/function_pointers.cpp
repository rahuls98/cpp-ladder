#include <iostream>
#include <any>
#include <utility>

#define DOUBLE std::any_cast<double>

class C {
    std::any var1 = 5.6;

    static double getDouble(std::any* addr) {
        return DOUBLE(*addr);
    }

public:
    template <typename cT>
    cT caster(std::pair<cT(*)(std::any*), std::any*> p) {
        //calling getDouble using the function pointer passed as a parameter
        return p.first(p.second);
    } 

    auto getPair() {
        double(*fptr)(std::any*) {getDouble};   
        //function pointer fptr points to the getDouble function. 
        return std::make_pair(fptr, &var1);
    }
};

int main() {
    C obj;
    auto p = obj.getPair();
    double var = obj.caster(p);

    std::cout<<var<<std::endl;  // 5.6

    return 0;
}