#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

    std::cout << "\n========== TEST 1: INTERN - VALID FORM CREATION ==========\n";
    
    Intern someRandomIntern;
    AForm* shrubForm = NULL;
    AForm* roboForm = NULL;
    AForm* pardonForm = NULL;

    try {
        shrubForm = someRandomIntern.makeForm("shrubbery creation", "home");
        if (shrubForm) {
            std::cout << *shrubForm << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        roboForm = someRandomIntern.makeForm("robotomy request", "Bender");
        if (roboForm) {
            std::cout << *roboForm << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        pardonForm = someRandomIntern.makeForm("presidential pardon", "Arthur");
        if (pardonForm) {
            std::cout << *pardonForm << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 2: INTERN - INVALID FORM NAMES ==========\n";

    AForm* invalidForm1 = someRandomIntern.makeForm("invalid form", "target");
    if (invalidForm1 == NULL) {
        std::cout << "Form creation failed as expected (NULL returned)" << std::endl;
    }

    AForm* invalidForm2 = someRandomIntern.makeForm("shrubbery", "target");
    if (invalidForm2 == NULL) {
        std::cout << "Form creation failed as expected (NULL returned)" << std::endl;
    }

    AForm* invalidForm3 = someRandomIntern.makeForm("ROBOTOMY REQUEST", "target");
    if (invalidForm3 == NULL) {
        std::cout << "Form creation failed as expected - case sensitive (NULL returned)" << std::endl;
    }

    std::cout << "\n========== TEST 3: INTERN - FORM SIGNING AND EXECUTION ==========\n";

    Bureaucrat lowGrade("LowGrade", 150);
    Bureaucrat midGrade("MidGrade", 45);
    Bureaucrat highGrade("HighGrade", 1);

    std::cout << lowGrade << std::endl;
    std::cout << midGrade << std::endl;
    std::cout << highGrade << std::endl;

    // Test signing with different grades
    if (shrubForm) {
        std::cout << "\n--- Testing Shrubbery Form ---" << std::endl;
        try {
            lowGrade.signForm(*shrubForm);
        }
        catch (std::exception &e) {
            std::cerr << "Signing error: " << e.what() << std::endl;
        }

        try {
            highGrade.signForm(*shrubForm);
            highGrade.execForm(*shrubForm);
        }
        catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    if (roboForm) {
        std::cout << "\n--- Testing Robotomy Form ---" << std::endl;
        try {
            midGrade.signForm(*roboForm);
            midGrade.execForm(*roboForm); // should succeed as grade 45 is exactly the requirement
        }
        catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Try executing again (multiple attempts to see randomness)
        std::cout << "\nAttempting robotomy again:" << std::endl;
        try {
            highGrade.execForm(*roboForm);
        }
        catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    if (pardonForm) {
        std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
        try {
            midGrade.signForm(*pardonForm); // grade 45 too low, needs 25
        }
        catch (std::exception &e) {
            std::cerr << "Signing error: " << e.what() << std::endl;
        }

        try {
            highGrade.signForm(*pardonForm);
            highGrade.execForm(*pardonForm);
        }
        catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    std::cout << "\n========== TEST 4: INTERN - MULTIPLE INTERNS ==========\n";

    Intern intern1;
    Intern intern2;
    Intern intern3;

    AForm* form1 = intern1.makeForm("shrubbery creation", "garden");
    AForm* form2 = intern2.makeForm("robotomy request", "criminal");
    AForm* form3 = intern3.makeForm("presidential pardon", "prisoner");

    if (form1 && form2 && form3) {
        std::cout << "\nAll three interns successfully created forms!" << std::endl;
        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl;

        try {
            highGrade.signForm(*form1);
            highGrade.signForm(*form2);
            highGrade.signForm(*form3);

            highGrade.execForm(*form1);
            highGrade.execForm(*form2);
            highGrade.execForm(*form3);
        }
        catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    std::cout << "\n========== TEST 5: INTERN - COPY CONSTRUCTOR AND ASSIGNMENT ==========\n";

    Intern intern4;
    Intern intern5(intern4); // copy constructor
    Intern intern6;
    intern6 = intern4; // assignment operator

    AForm* form4 = intern5.makeForm("shrubbery creation", "copy_test");
    AForm* form5 = intern6.makeForm("robotomy request", "assignment_test");

    if (form4 && form5) {
        std::cout << "Copy and assignment work correctly!" << std::endl;
        std::cout << *form4 << std::endl;
        std::cout << *form5 << std::endl;
    }

    std::cout << "\n========== TEST 6: INTERN - ERROR HANDLING ==========\n";

    // Test execution without signing
    AForm* unsignedForm = someRandomIntern.makeForm("shrubbery creation", "unsigned_test");
    if (unsignedForm) {
        try {
            highGrade.execForm(*unsignedForm);
        }
        catch (std::exception &e) {
            std::cerr << "Expected error (unsigned form): " << e.what() << std::endl;
        }
    }

    // Test with bureaucrat who has insufficient grade
    AForm* testForm = someRandomIntern.makeForm("presidential pardon", "test_target");
    if (testForm) {
        try {
            lowGrade.signForm(*testForm);
        }
        catch (std::exception &e) {
            std::cerr << "Expected error (grade too low to sign): " << e.what() << std::endl;
        }

        try {
            highGrade.signForm(*testForm);
            lowGrade.execForm(*testForm);
        }
        catch (std::exception &e) {
            std::cerr << "Expected error (grade too low to execute): " << e.what() << std::endl;
        }
    }

    std::cout << "\n========== CLEANUP ==========\n";

    // Clean up dynamically allocated forms
    delete shrubForm;
    delete roboForm;
    delete pardonForm;
    delete form1;
    delete form2;
    delete form3;
    delete form4;
    delete form5;
    delete unsignedForm;
    delete testForm;

    std::cout << "All forms cleaned up successfully!" << std::endl;

    std::cout << "\n========== END OF TESTS ==========\n";

    return 0;
}
