#include "AForm.hpp"

AForm::
GradeTooHighException::GradeTooHighException(const string& msg) throw() :
m_message(msg) {}

AForm::
GradeTooHighException::~GradeTooHighException(void) throw() {}

const char*
AForm::
GradeTooHighException::what(void) const throw() {
    return m_message.c_str();
}

AForm::
GradeTooLowException::GradeTooLowException(const string& msg) throw() :
m_message(msg) {}

AForm::
GradeTooLowException::~GradeTooLowException(void) throw() {}

const char*
AForm::
GradeTooLowException::what(void) const throw() {
    return m_message.c_str();
}

AForm::AForm(void) :
    name("root"), is_signed(false),
    grade_to_sign(1),
    grade_to_exec(1) {}

AForm::AForm(const string& form_name, const int& _grade_to_sign, const int& _grade_to_exec) :
    name(form_name), is_signed(false),
    grade_to_sign(_grade_to_sign),
    grade_to_exec(_grade_to_exec) {
    if (_grade_to_sign < 1  || _grade_to_exec < 1 )
        throw AForm::GradeTooHighException("Grade too high");
    if (_grade_to_sign > 150  || _grade_to_exec > 150 )
        throw AForm::GradeTooLowException("Grade too low");
}

AForm::~AForm() {}

AForm::AForm(const F& other) :
    name(other.name), is_signed(false),
    grade_to_sign(other.grade_to_sign),
    grade_to_exec(other.grade_to_exec) {
}

F& AForm::operator=(const F& other) {
    if (&other == this)
        return *this;
    return *this;
}

const string& AForm::getName(void) const { return name; }
const int& AForm::getToSignGrade(void) const { return grade_to_sign; }
const int& AForm::getToExecGrade(void) const { return grade_to_exec; }
const bool& AForm::getIsSigned(void) const { return is_signed; }

void AForm::beSigned(const B* bureaucrat) {
    if (is_signed) {
        std::cerr << "Form already signed!" << std::endl;
        return ;
    }
    if (bureaucrat->getGrade() > grade_to_sign)
        throw AForm::GradeTooLowException("Grade too low");
    else if (bureaucrat->getGrade() <= grade_to_sign)
        is_signed = true;
    std::cout << bureaucrat->getName() << " signed " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const F& form) {
    os << "Name: " << form.getName() << "\n"
       << "Grade to execute: " << form.getToExecGrade() << "\n"
       << "Grade to sign: " << form.getToSignGrade() << "\n"
       << "Status: " << (form.getIsSigned() ? "Signed" : "Not Signed");
    
    return os;
}
