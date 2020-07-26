#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <any>

#define br() {std::cout<<std::endl;}

#define STRING std::any_cast<std::string>
#define CHAR std::any_cast<char>
#define INT std::any_cast<int>
#define DOUBLE std::any_cast<double>

class CPPON {
    std::vector< std::pair<std::any, std::any> > CPPON_Obj;
    std::unordered_map<std::string, int> hashString = {
        {"NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE", 0},
        {"c", 1},
        {"i", 2},
        {"d", 3}
    };

    void printCasted(std::any val) {
        std::string key = std::string(val.type().name());
        int c = hashString[key];
        switch( c ) {
            case 0 : std::cout<<STRING(val); break;
            case 1 : std::cout<<CHAR(val); break;
            case 2 : std::cout<<INT(val); break;
            case 3 : std::cout<<DOUBLE(val); break;
            default: std::cout<<"Unknown type"; break;
        }
        return;
    }

public:
    CPPON() { this->CPPON_Obj = {}; }

    template<typename kT, typename vT>
    void insert(kT key, vT value) {
        std::pair<kT,vT> p = std::make_pair(key,value);
        CPPON_Obj.push_back(p);
    }

    void print() {
        for(auto p: CPPON_Obj) {
            printCasted(p.first);
            std::cout<<": ";
            printCasted(p.second);
            std::cout<<std::endl;
        }
    }

    void operator[](std::string ind) {
        for(auto &p: CPPON_Obj) {
            std::string key = STRING(p.first);
            if(key == ind) {
                printCasted(p.second);
                return;
            }
        } 
        std::cout<<"No such key!"<<std::endl;
    }

    auto getValue(std::string ind) {
        for(auto &p: CPPON_Obj) {
            std::string key = STRING(p.first);
            if(key == ind) {
                return &(p.second);
            }
        }
    }

    void remove(std::string ind) {
        for(auto p=CPPON_Obj.begin(); p!=CPPON_Obj.end(); p++) {
            std::string key = STRING(p->first);
            if(key == ind) {
                CPPON_Obj.erase(p);
                return;
            }
        }
    }

    template<typename vT>
    void update(std::string ind, vT val) {
        for(auto p=CPPON_Obj.begin(); p!=CPPON_Obj.end(); p++) {
            std::string key = STRING(p->first);
            if(key == ind) {
                p->second = val;
                return;
            }
        }
    }
};

int main() {
    CPPON usn_188;

    usn_188.insert(std::string("Name"), std::string("Rahul"));
    usn_188.insert(std::string("Age"), 21);
    usn_188.insert(std::string("Gender"), 'M');
    usn_188.insert(std::string("CGPA"), 8.17);
    br();

    usn_188.print();
    /*
        Name: Rahul
        Age: 21
        Gender: M
        CGPA: 8.17
    */
    br();

    usn_188["Name"]; br();      // Rahul
    usn_188["Age"]; br();       // 21
    usn_188["Gender"]; br();    // M

    br();

    double cgpa = DOUBLE(*(usn_188.getValue("CGPA")));
    std::cout<<"CGPA: "<<cgpa; br();    // CGPA: 8.17

    usn_188.remove("Gender"); 
    usn_188.update("CGPA", 8.19); br();

    usn_188.print(); br();
    /*
        Name: Rahul
        Age: 21
        CGPA: 8.19
    */

    usn_188["Gender"];  // No such key!

    br(); return 0;
}