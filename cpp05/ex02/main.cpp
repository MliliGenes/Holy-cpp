#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {

    try {
        F divorce_doc1("divorce_doc_1", -1, 1);
        std::cout << divorce_doc1 << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    try {
        F divorce_doc1("divorce_doc_1", 152, 1);
        std::cout << divorce_doc1 << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    try {
        B boutaina("boutaina", 5);
        std::cout << boutaina << std::endl;

        B ikram("ikram", 1);
        std::cout << ikram << std::endl;

        F divorce_doc1("divorce_doc_1", 2, 1);
        std::cout << divorce_doc1 << std::endl;

        F divorce_doc2("divorce_doc_2", 2, 1);
        std::cout << divorce_doc2 << std::endl;

        ikram.signForm(divorce_doc1);
        std::cout << divorce_doc1 << std::endl;

        boutaina.signForm(divorce_doc1);
        std::cout << divorce_doc1 << std::endl;

        boutaina.signForm(divorce_doc2);
        std::cout << divorce_doc2 << std::endl;
    } catch ( std::exception& e ) {
        std::cerr << e.what() << std::endl;
    } 
}