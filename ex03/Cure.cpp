#include "Cure.hpp"

#include <iostream>
#include "Character.hpp"

Cure::Cure() : AMateria()
{
    this->_type = "cure";
}

Cure::Cure(const Cure& Other) : AMateria(Other.getType())
{}

Cure& Cure::operator=(const Cure& Other)
{
    this->_type = Other.getType();
    return (*this);
}

Cure::~Cure()
{}

AMateria* Cure::clone() const
{
    AMateria* newMateria = new Cure();
    return (newMateria);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}