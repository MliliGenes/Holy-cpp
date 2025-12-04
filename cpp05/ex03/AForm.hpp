#pragma once

#ifndef AFORM_HPP
#define AFORM_HPP

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

        class FormNotSignedException : public std::exception {
            private:
                string m_message;

            public:
                FormNotSignedException(const string& msg) throw();
                virtual ~FormNotSignedException() throw();
                const char* what() const throw();
        };


        AForm(void);
        AForm(const string& form_name, const int& grade_to_sign, const int& grade_to_exec);
        virtual ~AForm();

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
        void execute(Bureaucrat const & executor); // idk what this should do exactly

    protected:
        virtual void beExecuted() = 0;
};

std::ostream& operator<<(std::ostream& os, const F& form);

#endif
