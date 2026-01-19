#pragma once

class Base;

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

class Base {
    public:
        virtual ~Base() {}
};