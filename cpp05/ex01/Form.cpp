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
        
}