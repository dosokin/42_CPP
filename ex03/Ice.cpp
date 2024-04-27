#include "Ice.hpp"
#include "Character.hpp"

#include <iostream>

Ice::Ice() : AMateria()
{
    this->_type = "ice";
}

Ice::Ice(const Ice& Other) : AMateria(Other.getType())
{}

Ice& Ice::operator=(const Ice& Other)
{
    this->_type = Other.getType();
    return (*this);
}

Ice::~Ice()
{}

AMateria* Ice::clone() const
{
    AMateria* newMateria = new Ice();
    return (newMateria);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}