#pragma once

#include "AForm.hpp"

class PresidentialPardonForm;

typedef PresidentialPardonForm President;

class PresidentialPardonForm : public AForm {
    private:
        string target;
        PresidentialPardonForm();

    public:

        PresidentialPardonForm(const string& _target);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const President& other);
        President& operator=(const President& other);

        const string& getTarget(void)
            const; // hmmmmmmmm

        // void execute(Bureaucrat const & executor); this is fucking useless since i am validating everything on the base class :-)
    protected:
        void beExecuted(); //override the bitch
};

std::ostream& operator<<(std::ostream& os, const President& form);