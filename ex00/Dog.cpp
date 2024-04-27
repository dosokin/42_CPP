#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& other): Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = "Dog";
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment copy constructor called" << std::endl;
    this->type = other.type;
    return (*this);
}

void        Dog::makeSound() const
{
    std::cout << "gaf gaf" << std::endl;
}


Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}