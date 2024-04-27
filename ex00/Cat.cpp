#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& other): Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = "Cat";
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment copy constructor called" << std::endl;
    this->type = other.type;
    return (*this);
}

void        Cat::makeSound() const
{
    std::cout << "miaaaaaaaaaaou" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}
