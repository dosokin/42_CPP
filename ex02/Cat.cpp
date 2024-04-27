#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->catBrain = new Brain();
}

Cat::Cat(const Cat& other): AAnimal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = "Cat";
    this->catBrain = new Brain(other.getBrain());
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment copy constructor called" << std::endl;
    this->type = other.type;
    delete(this->catBrain);
    this->catBrain = new Brain(other.getBrain());
    return (*this);
}

Brain       Cat::getBrain() const
{
    return (*this->catBrain);
}

void        Cat::makeSound() const
{
    std::cout << "miaaaaaaaaaaou" << std::endl;
}

Cat::~Cat()
{
    delete this->catBrain;
    std::cout << "Cat destructor called" << std::endl;
}
