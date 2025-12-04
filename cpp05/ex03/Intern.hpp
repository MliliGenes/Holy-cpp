#pragma once

#include "AForm.hpp"
class Intern;

typedef Intern I;

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const I& other);
        Intern& operator=(const I& other);

        AForm* makeForm(const string& form_name, const string& form_target) const;
};