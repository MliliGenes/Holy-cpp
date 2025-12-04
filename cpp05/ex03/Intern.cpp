#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const I& other) {
    (void)other;
}
I& Intern::operator=(const I& other) {
    if (this == &other)
        return *this;
    return *this;
}

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

typedef AForm* (*FormCreator)(const std::string& target);

AForm* Intern::makeForm(const string& form_name, const string& form_target) const {
    static const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreator creators[3] = {
        createShrubbery,
        createRobotomy,
        createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (form_name == formNames[i]) {
            std::cout << "Intern creates " << form_name << std::endl;
            return (*creators[i])(form_target);
        }
    }

    std::cout << "Intern cannot create form: " << form_name << std::endl;
    return NULL;
}