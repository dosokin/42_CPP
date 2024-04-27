#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("justAnAnimal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal assignment copy constructor called" << std::endl;
    this->type = other.type;
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void        Animal::makeSound() const
{
}

Animal::~Animal()
{
    std::cout << "Animal's of type " << this->type <<" destructor called" << std::endl;
}
