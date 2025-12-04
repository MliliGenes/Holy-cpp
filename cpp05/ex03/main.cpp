#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    std::cout << "\n========== TEST 1: FORM CREATION ERRORS ==========\n";

    try {
        ShrubberyCreationForm badForm("home"); // valid, no exception
        std::cout << badForm << std::endl;
    } 
    catch (std::exception &e) {
        std::cerr << "Error creating Shrubbery form: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 2: BUREAUCRAT CREATION ERRORS ==========\n";

    try {
        Bureaucrat bad("TooHigh", 0);  // should throw GradeTooHighException
    } 
    catch (std::exception &e) {
        std::cerr << "Caught exception (grade too high): " << e.what() << std::endl;
    }

    try {
        Bureaucrat bad("TooLow", 200); // should throw GradeTooLowException
    } 
    catch (std::exception &e) {
        std::cerr << "Caught exception (grade too low): " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 3: VALID BUREAUCRATS ==========\n";

    Bureaucrat low("LowRank", 150);
    Bureaucrat mid("MidRank", 70);
    Bureaucrat high("HighRank", 1);

    std::cout << low << "\n" << mid << "\n" << high << "\n";

    std::cout << "\n========== TEST 4: SIGNING ERRORS ==========\n";

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur");

    // too low to sign
    try {
        low.signForm(shrub);
    } 
    catch (std::exception &e) {
        std::cerr << "Signing error (shrub): " << e.what() << std::endl;
    }

    // mid can sign robotomy
    try {
        mid.signForm(robo);
    } 
    catch (std::exception &e) {
        std::cerr << "Signing error (robotomy): " << e.what() << std::endl;
    }

    // high can sign everything
    try {
        high.signForm(pardon);
    } 
    catch (std::exception &e) {
        std::cerr << "Signing error (pardon): " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 5: EXECUTION ERRORS ==========\n";

    // attempt to execute! (unsigned + low grade)
    try {
        low.execForm(shrub); // shrub unsigned, low grade
    }
    catch (std::exception &e) {
        std::cerr << "Execution error (shrub unsigned): " << e.what() << std::endl;
    }

    try {
        mid.execForm(robo); // signed but mid has grade 70, exec requires 45
    }
    catch (std::exception &e) {
        std::cerr << "Execution error (robotomy grade too low): " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 6: SUCCESSFUL EXECUTIONS ==========\n";

    try {
        high.signForm(shrub);
        high.execForm(shrub);
    } 
    catch (std::exception &e) {
        std::cerr << "Shrub execution error: " << e.what() << std::endl;
    }

    try {
        high.execForm(robo); // already signed by mid
    } 
    catch (std::exception &e) {
        std::cerr << "Robotomy execution error: " << e.what() << std::endl;
    }

    try {
        high.execForm(pardon); // already signed
    }
    catch (std::exception &e) {
        std::cerr << "Pardon execution error: " << e.what() << std::endl;
    }

    std::cout << "\n========== END OF TESTS ==========\n";

    return 0;
}
