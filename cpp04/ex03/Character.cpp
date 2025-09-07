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
    
    initStash();
    
    for (int i = 0; i < other.index; i++)
    {
        if (other.stash[i])
            stash[i] = other.stash[i]->clone();
    }
    index = other.index;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = 0;
            }
        }
        
        for (int i = 0; i < index; i++)
        {
            if (stash[i])
            {
                delete stash[i];
                stash[i] = 0;
            }
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = 0;
        }
        
        if (capacity < other.index)
        {
            delete[] stash;
            capacity = other.capacity;
            stash = new AMateria*[capacity];
            for (int i = 0; i < capacity; i++)
                stash[i] = 0;
        }
        else
        {
            for (int i = index; i < capacity; i++)
                stash[i] = 0;
        }
        
        for (int i = 0; i < other.index; i++)
        {
            if (other.stash[i])
                stash[i] = other.stash[i]->clone();
            else
                stash[i] = 0;
        }
        index = other.index;
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
        AMateria** newStash = new AMateria*[capacity * 2];
        for (int i = 0; i < capacity; i++)
            newStash[i] = stash[i];
        for (int i = capacity; i < capacity * 2; i++)
            newStash[i] = 0;

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
        {
            stash[index++] = _inventory[idx];
        }
        else if (capacity == index)
        {
            AMateria** newStash = new AMateria*[capacity * 2];
            for (int i = 0; i < capacity; i++)
                newStash[i] = stash[i];
            for (int i = capacity; i < capacity * 2; i++)
                newStash[i] = 0;
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
        stash[i] = 0;
}