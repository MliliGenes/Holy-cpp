#include "PresidentialPardonForm.hpp"

PresidentialPardonForm
::PresidentialPardonForm(const string& _target)
    : AForm("PresidentialPardonForm", 25, 5),
    target(_target) {}

PresidentialPardonForm
::~PresidentialPardonForm() {}

PresidentialPardonForm
::PresidentialPardonForm(const President& other)
    : AForm("PresidentialPardonForm", 25, 5),
    target(other.target) {}

President&
PresidentialPardonForm
::operator=(const President& other) {
    if (&other == this)
        return *this;
    return *this;
}

const string&
PresidentialPardonForm::
getTarget(void) const {
    return target;
}

void
PresidentialPardonForm::beExecuted(void) {
    // print a fucking tree to a file i guess
    
}

std::ostream& operator<<(std::ostream& os, const President& form) {
    os << "Name: " << form.getName() << "\n"
       << "Target: " << form.getTarget() << "\n"
       << "Grade to sign: " << form.getToSignGrade() << "\n"
       << "Grade to execute: " << form.getToExecGrade() << "\n"
       << "Status: " << (form.getIsSigned() ? "Signed" : "Not Signed");
    
    return os;
}