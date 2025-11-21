#pragma once

#include "AForm.hpp"

class RobotomyRequestForm;

typedef RobotomyRequestForm Robotomy;

class RobotomyRequestForm : public AForm {
    private:
        string target;

        RobotomyRequestForm();

    public:

        RobotomyRequestForm(const string& _target);
        ~RobotomyRequestForm();

        RobotomyRequestForm(const Robotomy& other);
        Robotomy& operator=(const Robotomy& other);

        const string& getTarget(void)
            const; // hmmmmmmmm

        // void execute(Bureaucrat const & executor); this is fucking useless since i am validating everything on the base class :-)
    protected:
        void beExecuted(); //override the bitch
};