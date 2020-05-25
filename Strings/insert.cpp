#include <iostream>
#include <string>

#define log(x) {std::cout<<x<<std::endl;}

int main() {
    std::string s = "xmplr"; 
    log(s);

    s.insert(0, "E"); //(index, char)
    s.insert(2, "e");
    log(s); //Exemplr

    s.insert(6, "aaa"); //(index, str)
    log(s); //Exemplaaar

    s.insert(10, " is an example string.", 3, 11); //(index, str, str_index, ch_count)
    log(s); //Exemplaaar an example

    s.insert(s.cbegin()+s.find_last_of('e')+1, ':'); //(iterator, ch)
    log(s); //Exemplaaar an example:

    s.insert(s.cbegin()+s.find_first_of(':')+1, 2, '='); //(iterator, ch_count, ch)
    log(s); //Exemplaaar an example:==
    return 0;
}