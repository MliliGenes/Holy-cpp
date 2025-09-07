#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <vector>

// void leakCheck()
// {
//     system("leaks ex03");
// }

int main()
{
    // atexit(leakCheck);
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    ICharacter* danon = new Character(*(Character *)bob);

    // Equip 4 Materia (max slots)
    AMateria* tmp1 = src->createMateria("ice");
    AMateria* tmp2 = src->createMateria("cure");
    AMateria* tmp3 = src->createMateria("ice");
    AMateria* tmp4 = src->createMateria("cure");
    me->equip(tmp1);
    me->equip(tmp2);
    me->equip(tmp3);
    me->equip(tmp4);

    // Try to equip a 5th Materia (should fail or be ignored)
    AMateria* tmp5 = src->createMateria("ice");
    me->equip(tmp5);

    // Unequip slot 1 and stash it
    me->unequip(1);

    // Unequip slot 2 and stash it
    me->unequip(2);

    // Equip another Materia in the freed slot
    AMateria* tmp6 = src->createMateria("cure");
    me->equip(tmp6);

    // Use all equipped Materia on bob
    for (int i = 0; i < 4; ++i)
        me->use(i, *bob);

    std::cout << "---- Testing with another character ----" << std::endl;

    // Use all equipped Materia on bob
    for (int i = 0; i < 4; ++i)
        me->use(i, *danon);

    // Clean up
    delete bob;
    delete danon;
    delete me;
    delete src;

    return 0;
}