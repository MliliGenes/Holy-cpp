#pragma once

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm;
typedef AForm F;

class AForm {
    private:
        const string    name;
        bool            is_signed;
        const int       grade_to_sign;
        const int       grade_to_exec;

        F& operator=(const F& other);

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

        AForm();
        AForm(const string& form_name, const int& grade_to_sign, const int& grade_to_exec);
        virtual ~AForm() = 0;

        AForm(const F& other);

        const string& getName(void)
            const;
        const int& getToSignGrade(void)
            const;
        const int& getToExecGrade(void)
            const;
        const bool& getIsSigned(void)
            const;
        
        void beSigned(const B* bureaucrat); // throw this shit Form::GradeTooLowException
};

std::ostream& operator<<(std::ostream& os, const F& form);

#endif
