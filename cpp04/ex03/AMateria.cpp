#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        // Type should not be copied according to subject
        // _type = other._type;
    }
    return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    // Base implementation - does nothing
}
