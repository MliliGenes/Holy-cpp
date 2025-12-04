#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm
::ShrubberyCreationForm(const string& _target)
    : AForm("ShrubberyCreationForm", 145, 137),
    target(_target) {}

ShrubberyCreationForm
::~ShrubberyCreationForm() {}

ShrubberyCreationForm
::ShrubberyCreationForm(const Shrubbery& other)
    : AForm("ShrubberyCreationForm", 145, 137),
    target(other.target) {}

Shrubbery&
ShrubberyCreationForm
::operator=(const Shrubbery& other) {
    if (&other == this)
        return *this;
    return *this;
}

const string&
ShrubberyCreationForm::
getTarget(void) const {
    return target;
}

void
ShrubberyCreationForm::beExecuted(void) {
    // print a fucking tree to a file i guess
    std::ofstream outfile(target.append("_shrubbery").c_str());
    if (!outfile.is_open())
        throw std::runtime_error("file bad trippa :(");
    outfile << TREE_ASCI;
    outfile.close();
}

std::ostream& operator<<(std::ostream& os, const Shrubbery& form) {
    os << "Name: " << form.getName() << "\n"
       << "Target: " << form.getTarget() << "\n"
       << "Grade to sign: " << form.getToSignGrade() << "\n"
       << "Grade to execute: " << form.getToExecGrade() << "\n"
       << "Status: " << (form.getIsSigned() ? "Signed" : "Not Signed");
    
    return os;
}