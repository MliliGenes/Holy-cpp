#include "Form.hpp"

Form::
GradeTooHighException::GradeTooHighException(const string& msg) throw() :
m_message(msg) {}

Form::
GradeTooHighException::~GradeTooHighException(void) throw() {}

const char*
Form::
GradeTooHighException::what(void) const throw() {
    return m_message.c_str();
}

Form::
GradeTooLowException::GradeTooLowException(const string& msg) throw() :
m_message(msg) {}

Form::
GradeTooLowException::~GradeTooLowException(void) throw() {}

const char*
Form::
GradeTooLowException::what(void) const throw() {
    return m_message.c_str();
}

Form::Form(void) :
    name("root"), is_signed(false),
    grade_to_sign(1),
    grade_to_exec(1) {}

Form::Form(const string& form_name, const int& _grade_to_sign, const int& _grade_to_exec) :
    name(form_name), is_signed(false),
    grade_to_sign(_grade_to_sign),
    grade_to_exec(_grade_to_exec) {
    if (_grade_to_sign < 1  || _grade_to_exec < 1 )
        throw Form::GradeTooHighException("Grade too high");
    if (_grade_to_sign > 150  || _grade_to_exec > 150 )
        throw Form::GradeTooLowException("Grade too low");
}

Form::~Form() {}

Form::Form(const F& other) :
    name(other.name), is_signed(false),
    grade_to_sign(other.grade_to_sign),
    grade_to_exec(other.grade_to_exec) {
}

F& Form::operator=(const F& other) {
    if (&other == this)
        return *this;
    return *this;
}

const string& Form::getName(void) const { return name; }
const int& Form::getToSignGrade(void) const { return grade_to_sign; }
const int& Form::getToExecGrade(void) const { return grade_to_exec; }
const bool& Form::getIsSigned(void) const { return is_signed; }

void Form::beSigned(const B* bureaucrat) {
    if (is_signed) {
        std::cerr << "Form already signed!" << std::endl;
        return ;
    }
    if (bureaucrat->getGrade() > grade_to_sign)
        throw Form::GradeTooLowException("Grade too low");
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
