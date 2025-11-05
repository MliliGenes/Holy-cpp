#include "Bureaucrat.hpp"

Bureaucrat::
GradeTooHighException::GradeTooHighException(const string& msg) throw() : m_message(msg) {}

Bureaucrat::
GradeTooHighException::~GradeTooHighException(void) throw() {}

const char*
Bureaucrat::
GradeTooHighException::what() const throw() {
	return m_message.c_str();
}

Bureaucrat::
GradeTooLowException::GradeTooLowException(const string& msg) throw() : m_message(msg) {}

Bureaucrat::
GradeTooLowException::~GradeTooLowException(void) throw() {}

const char*
Bureaucrat::
GradeTooLowException::what() const throw() {
	return m_message.c_str();
}

Bureaucrat::Bureaucrat(void) : name("root"), grade(1) {}

Bureaucrat::Bureaucrat(const string& _name, const int& _grade) : name(_name) {
    if (_grade > 150) {
		throw Bureaucrat::GradeTooLowException("");
    }
    if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException("");
    }
	grade = _grade;
}

Bureaucrat::Bureaucrat( const B& other ) : name(other.name) {
	grade = other.grade;
}

Bureaucrat::~Bureaucrat() { std::cout << "bye" << std::endl; }

B& Bureaucrat::operator=(const B& other) {
	if (this == &other)
		return *this;
	grade = other.grade;
	return *this;
}

const int& Bureaucrat::getGrade(void) const {
	return grade;
}

const string& Bureaucrat::getName(void) const {
	return name;
}

B& Bureaucrat::promote(void) {
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException("");
	grade--;
	return *this;
}

B& Bureaucrat::promote(int to_promote) {
	if (grade - to_promote < 1)
		throw Bureaucrat::GradeTooHighException("");
	grade -= to_promote;
	return *this;
}

B& Bureaucrat::demote(void) {
	if (grade == 150)
		throw Bureaucrat::GradeTooHighException("");
	grade++;
	return *this;
}

B& Bureaucrat::demote(int to_demote) {
	if (grade + to_demote > 150)
		throw Bureaucrat::GradeTooLowException("");
	grade += to_demote;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const B& some_dude) {
    os << some_dude.getName() << ", bureaucrat grade " << some_dude.getGrade();
    return os;
}