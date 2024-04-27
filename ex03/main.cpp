#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
    MateriaSource* src = new MateriaSource();
    MateriaSource ppc;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ppc = *src;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = NULL;
    tmp = ppc.createMateria("cure");
    AMateria *tmp_bis = tmp->clone();
    me->equip(tmp);
    std::cout << tmp << std::endl;
    tmp = NULL;
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    bob->equip(tmp_bis);
    bob->equip(tmp_bis);
    bob->use(0, *me);
    bob->use(0, *me);
    bob->use(1, *me);
    delete bob;
    delete me;
    delete src;
    return 0;
}