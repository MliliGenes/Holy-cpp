#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::
RobotomyRequestForm(const string& _target)
: AForm("RobotomyRequestForm", 72, 45),
target(_target) {

}

RobotomyRequestForm::
~RobotomyRequestForm() {}

RobotomyRequestForm::
RobotomyRequestForm(const Robotomy& other)
: AForm("RobotomyRequestForm", 72, 45),
target(other.target) {}

Robotomy& RobotomyRequestForm::
operator=(const Robotomy& other) {
    if (&other == this)
        return *this;
    return *this;
}

const string& RobotomyRequestForm::
getTarget(void) const {
    return target;
}

void
RobotomyRequestForm::beExecuted(void) {
    std::srand(std::time(NULL));
    int prob = std::rand() % 2;
    if (prob) {
        std::cout << "literally drilling noises..." << "\n"
            << target << " has been robotomized" << std::endl;
    } else {
        std::cerr << "the robotomy failed" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Robotomy& form) {
    os << "Name: " << form.getName() << "\n"
       << "Target: " << form.getTarget() << "\n"
       << "Grade to execute: " << form.getToExecGrade() << "\n"
       << "Grade to sign: " << form.getToSignGrade() << "\n"
       << "Status: " << (form.getIsSigned() ? "Signed" : "Not Signed");
    
    return os;
}