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

void
ShrubberyCreationForm::beExecuted(void) {
    // print a fucking tree to a file i guess
    std::ofstream outfile(target.append("_shrubbery").c_str());
    if (!outfile.is_open())
        throw std::runtime_error("file bad trippa :(");
    outfile << TREE_ASCI;
    outfile.close();
}