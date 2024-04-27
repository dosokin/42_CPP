#include "Animal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("justAnAAnimal")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other): type(other.type)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    std::cout << "AAnimal assignment copy constructor called" << std::endl;
    this->type = other.type;
    return (*this);
}

std::string AAnimal::getType() const
{
    return (this->type);
}

void        AAnimal::makeSound() const
{
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal's of type " << this->type <<" destructor called" << std::endl;
}
