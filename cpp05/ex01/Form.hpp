#pragma once

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form;
typedef Form F;

class Form {
    private:
        const string    name;
        bool            is_signed;
        const int       grade_to_sign;
        const int       grade_to_exec;

    public:
        class GradeTooHighException : public std::exception {
            private:
                string m_message;

            public:
                GradeTooHighException(const string& msg) throw();
                virtual ~GradeTooHighException() throw();
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            private:
                string m_message;

            public:
                GradeTooLowException(const string& msg) throw();
                virtual ~GradeTooLowException() throw();
                const char* what() const throw();
        };

        Form();
        Form(const string& form_name, const int& grade_to_sign, const int& grade_to_exec);
        ~Form();

        Form(const F& other);
        F& operator=(const F& other);

        const string& getName(void)
            const;
        const int& getToSignGrade(void)
            const;
        const int& getToExecGrade(void)
            const;
        const bool& getIsSinged(void)
            const;
        
        void beSigned(B& dude); // throw this shit Form::GradeTooLowException
};

#endif
