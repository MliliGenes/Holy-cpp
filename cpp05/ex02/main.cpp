#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
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

    
    try {
        ShrubberyCreationForm form("chajara");
        std::cout << form << std::endl;
        
        RobotomyRequestForm form0("Mr roboto");
        std::cout << form0 << std::endl;

        B boutaina("boutaina", 5);
        // std::cout << boutaina << std::endl;

        B ikram("ikram", 1);
        // std::cout << ikram << std::endl;

        B saad("saad", 70);
        //

        saad.signForm(form0);
        saad.execForm(form0);

        ikram.signForm(form);
        ikram.execForm(form);

        ikram.signForm(form0);
        ikram.execForm(form0);


    } catch ( std::exception& e ) {
        std::cerr << e.what() << std::endl;
    } 
}