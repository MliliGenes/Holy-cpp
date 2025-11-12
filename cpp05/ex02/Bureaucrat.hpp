#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;
class Bureaucrat;

typedef std::string string;

typedef AForm F;
typedef Bureaucrat B;

class Bureaucrat {
    private:
        const string    name;
        int             grade;

    public:

        class GradeTooHighException : public std::exception {
            private:
                string m_message;

            public:
                GradeTooHighException(const string& message) throw();
                ~GradeTooHighException(void) throw();
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            private:
                string m_message;

            public:
                GradeTooLowException(const string& message) throw();
                ~GradeTooLowException(void) throw();
                const char* what() const throw();
        };

        Bureaucrat(void);
        Bureaucrat(const string& name, const int& grade);
        ~Bureaucrat(void);

        Bureaucrat(const B& other);
        B& operator=(const B& other);

        const int& getGrade(void)
            const;
        const string& getName(void)
            const;

        B& promote(void);
        B& promote(int to_promote);

        B& demote(void);
        B& demote(int to_demote);

        void signForm(F& form) const;
};

std::ostream& operator<<(std::ostream& os, const B& bureaucrat);

#endif
