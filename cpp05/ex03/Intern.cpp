#include "Intern.hpp"

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

AForm* Intern::makeForm(const string& form_name, const string& form_target) const {
    AForm* form;

    
}