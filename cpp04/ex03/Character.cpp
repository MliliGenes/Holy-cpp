#include "Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
    initStash();
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        
        // Delete existing materias
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = 0;
            }
        }
        
        // Deep copy new materias
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
    for (int i = 0; i < index; i++)
    {
        if (stash[i])
            delete stash[i];
    }
    delete[] stash;
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    // Try to place in inventory first
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return;
        }
    }

    if (index < capacity)
    {
        stash[index++] = m;
    }
    else if (capacity == index)
    {
        // Resize stash
        AMateria** newStash = new AMateria*[capacity * 2];
        for (int i = 0; i < capacity; i++)
            newStash[i] = stash[i];
        for (int i = capacity; i < capacity * 2; i++)
            newStash[i] = NULL;

        delete[] stash;
        stash = newStash;
        capacity *= 2;

        stash[index++] = m;
    }
}


void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
    {
        if (index < capacity)
            stash[index++] = _inventory[idx];
        else if (capacity == index)
        {
            AMateria** newStash = new AMateria*[capacity * 2];
            for (int i = 0; i < capacity; i++)
                newStash[i] = stash[i];
            for (int i = capacity; i < capacity * 2; i++)
                newStash[i] = NULL;
            delete[] stash;
            stash = newStash;
            capacity *= 2;
            stash[index++] = _inventory[idx];
        }
        _inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
    {
        _inventory[idx]->use(target);
    }
}

void Character::initStash(void)
{
    capacity = 100;
    index = 0;
    stash = new AMateria*[capacity];
    for (int i = 0; i < capacity; i++)
        stash[i] = NULL;
}