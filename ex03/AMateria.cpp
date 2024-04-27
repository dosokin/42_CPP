#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria()
{}

AMateria::AMateria(const AMateria& Other) : _type(Other.getType()) {
}

AMateria&   AMateria::operator=(const AMateria& Other)
{
    (void)Other;
    return (*this);
}

AMateria::~AMateria()
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
