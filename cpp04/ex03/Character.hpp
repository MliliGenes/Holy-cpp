#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* _inventory[4];

    // * garbage collector for unequipped materias
    int capacity;
    int index;
    AMateria** stash; // * Array to store unequipped materia pointers

public:
    Character(std::string const & name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();
    
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
    
    void initStash(void);
};

#endif
