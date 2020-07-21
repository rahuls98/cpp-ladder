#include <iostream>
#include <vector>
#include <utility>
#include <any>

class JSON {
    std::vector<std::pair<std::any, std::any>> JSON_Obj;

public:
    JSON() {
        this->JSON_Obj = {};
    }

    template<typename kT, typename vT>
    void insert(kT key, vT value) {
        std::pair<kT,vT> p = std::make_pair(key,value);
        JSON_Obj.push_back(p);
    }

    void print() {
        for(auto p: JSON_Obj) {
            std::cout<<p.first.type().name()<<": "<<p.second.type().name()<<std::endl;
        }
    }
};

int main() {
    JSON json;
    json.insert("age",20);
    json.insert("name","Rahul");
    json.print();

    return 0;
}