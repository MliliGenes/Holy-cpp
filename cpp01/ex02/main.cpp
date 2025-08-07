#include <iostream>
#include <string>


int main( void ) {

    std::string brain = "HI THIS IS BRAIN";

    std::string *stringPTR = &brain;
    std::string &stringREF = brain;
 
    std::cout << "=== Addresses ===" << std::endl;
    std::cout << "String variable address      : " << &brain << std::endl;
    std::cout << "Pointer variable address     : " << stringPTR << std::endl;
    std::cout << "Reference variable address   : " << &stringREF << std::endl;
    
    std::cout << "\n=== Values ===" << std::endl;
    std::cout << "Value of string variable     : " << brain << std::endl;
    std::cout << "Value pointed by stringPTR   : " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF   : " << stringREF << std::endl;

}

