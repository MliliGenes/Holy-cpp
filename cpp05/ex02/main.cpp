#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

    // try {
    //     F divorce_doc1("divorce_doc_1", -1, 1);
    //     std::cout << divorce_doc1 << std::endl;

    // } catch (std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // std::cout << std::endl;
    // std::cout << std::endl;

    // try {
    //     F divorce_doc1("divorce_doc_1", 152, 1);
    //     std::cout << divorce_doc1 << std::endl;

    // } catch (std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // std::cout << std::endl;
    // std::cout << std::endl;

    ShrubberyCreationForm base = ShrubberyCreationForm("dawdawd");
    AForm& a = base;
    a.beExecuted();

    
    try {
        ShrubberyCreationForm form("chajara");

        B boutaina("boutaina", 5);
        std::cout << boutaina << std::endl;

        B ikram("ikram", 1);
        std::cout << ikram << std::endl;

        ikram.signForm(form);
        ikram.execForm(form);

    } catch ( std::exception& e ) {
        std::cerr << e.what() << std::endl;
    } 
}