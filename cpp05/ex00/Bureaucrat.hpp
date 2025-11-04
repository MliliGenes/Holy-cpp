#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat;

typedef std::string string;
typedef Bureaucrat B;

class Bureaucrat {
    private:
        const string    name;
        int             grade;

    public:

        class GradeTooHighException : public std::exception {
            private:
                std::string m_message;

            public:
                GradeTooHighException(const std::string& message = "Grade too high") throw()
                    : m_message(message) {}

                virtual const char* what() const throw() {
                    return m_message.c_str();
                }

                virtual ~GradeTooHighException() throw() {}
        };

        class GradeTooLowException : public std::exception {
            private:
                std::string m_message;

            public:
                GradeTooLowException(const std::string& message = "Grade too low") throw()
                    : m_message(message) {}

                virtual const char* what() const throw() {
                    return m_message.c_str();
                }

                virtual ~GradeTooLowException() throw() {}
        };

        Bureaucrat(void);
        Bureaucrat(const string name, const int grade);
        ~Bureaucrat(void);

        Bureaucrat(const B& other);
        B& operator=(const B& other);

        int getGrade(void)
            const;
        string getName(void)
            const;

        B& promote(void);
        B& promote(int to_promote);

        B& demote(void);
        B& demote(int to_demote);
};

std::ostream& operator<<(std::ostream& os, const B& some_dude);

#endif
