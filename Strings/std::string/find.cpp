#include <iostream>
#include <string>

void sampleTest(std::string& sref) {
    //find(substr) returns the position of 'substr' if it is present
    //else it returns std::string::npos 
    
    if(sref.find("sample")==std::string::npos) {
        std::cout<<"Not sample string!"<<std::endl;
    } else {
        int pos = sref.find("sample");
        std::cout<<pos<<": ";
        std::cout<<"Sample string!"<<std::endl;
    }
}

int main() {
    std::string original = "This is my original string!";
    std::string sample = "This is my sample string!";

    sampleTest(original);
    sampleTest(sample);

    return 0;
}